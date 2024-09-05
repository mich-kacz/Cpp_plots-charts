#include "columnGraph.hpp"

#include "font.hpp"
#include "shapes.hpp"

#include <iostream>


ColumnGraph::ColumnGraph(const std::string &title)
{
    m_title = title;
    m_maxValue = 0.0;
    Window::update();
    draw();
}

ColumnGraph::ColumnGraph(const std::vector<DataSerie> &dataSeries, const std::string &title)
{
    m_dataSeries = dataSeries;
    m_title = title;
    calculate_max();
    draw();
}

void ColumnGraph::add_data_serie(const DataSerie &dataSerie)
{
    if (dataSerie.m_value > m_maxValue)
    {
        m_maxValue = dataSerie.m_value;
    }
    Graph::add_data_serie(dataSerie);
}

void ColumnGraph::calculate_max()
{
    for (const auto& dataSerie : m_dataSeries)
    {
        if (dataSerie.m_value > m_maxValue)
        {
            m_maxValue = dataSerie.m_value;
        }
    } 
}

void ColumnGraph::draw()
{
    Window::clear();

    int i = 0;
    double columnWidth = 0.8/m_dataSeries.size() * m_width;
    for (const auto& dataSerie : m_dataSeries)
    {
        double ratio = 0.8 * dataSerie.m_value / m_maxValue;

        double start_x = (0.1*m_width)+i*columnWidth;
        double start_y = ((1-ratio)-0.1)*m_height;
        double end_x = start_x + columnWidth;
        double end_y = 0.9 * m_height;
        Shapes::draw_rectangle(m_renderer, start_x, start_y, (end_x - start_x) + 1, (end_y - start_y) + 1, dataSerie.m_color);

        Shapes::draw_line(m_renderer, start_x, start_y, start_x, end_y);
        Shapes::draw_line(m_renderer, start_x, start_y, end_x, start_y);
        Shapes::draw_line(m_renderer, start_x, end_y, end_x, end_y);
        Shapes::draw_line(m_renderer, end_x, start_y, end_x, end_y);
        ++i;
    }

    if (!m_title.empty())
    {
        Font::show_text(m_renderer, m_title, m_height / 30, Color::Black, m_height / 100, (m_width / 2), true, true);
    }

    draw_legend();
    Window::update();
}

void ColumnGraph::draw_legend()
{
    int i = 1;
    for (const auto& dataSerie : m_dataSeries)
    {
        Shapes::draw_rectangle(m_renderer, 10, 16*i, 20, 16, dataSerie.m_color);

        std::string value = std::to_string(dataSerie.m_value);
        value = value.substr(0, value.find(".") + 2);

        std::string text = dataSerie.m_title + " - " + value;
        Font::show_text(m_renderer, text, 16, Color::Black, 16*i, 40);
        i++;
    }
}

