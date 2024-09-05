#include "pieGraph.hpp"

#include <iostream>

#include "font.hpp"
#include "shapes.hpp"


PieGraph::PieGraph(const std::string &title)
{
    m_title = title;
    m_totalSum = 0.0;
    Window::update();
    draw();
}

PieGraph::PieGraph(const std::vector<DataSerie> &dataSeries, const std::string &title)
{
    m_dataSeries = dataSeries;
    m_title = title;
    m_totalSum = calculate_sum();
    draw();
}

void PieGraph::add_data_serie(const DataSerie &dataSerie)
{
    m_totalSum += dataSerie.m_value;
    Graph::add_data_serie(dataSerie);
}

double PieGraph::calculate_sum()
{
    double sum = 0.0;
    for (const auto& dataSerie : m_dataSeries)
    {
        sum += dataSerie.m_value;
    } 
    return sum;
}

void PieGraph::draw()
{
    Window::clear();

    float startAngle = -M_PI / 2;
    float endAngle = 0.0;

    Font::show_text(m_renderer, m_title, 16, Color::Black, 0, m_width/2, true, true);

    int radius = (m_height > m_width ) ? (2 * m_width / 5) : (2 * m_height / 5);
    for (const auto& dataSerie : m_dataSeries)
    {
        float percent = dataSerie.m_value/m_totalSum;
        float angle = 2 * M_PI * percent;
        endAngle = startAngle + angle;

        Colors::set_color(m_renderer, dataSerie.m_color);
        draw_pie_chart(startAngle, endAngle, radius);
        startAngle = endAngle;
    }
    draw_legend();
    Window::update();
}

void PieGraph::draw_legend()
{
    int i = 1;
    for (const auto& dataSerie : m_dataSeries)
    {
        Shapes::draw_rectangle(m_renderer, 10, 16*i, 20, 16, dataSerie.m_color);
        std::string percent = std::to_string(dataSerie.m_value/m_totalSum*100);
        percent = percent.substr(0, percent.find(".") + 2) + "%";

        std::string value = std::to_string(dataSerie.m_value);
        value = value.substr(0, value.find(".") + 2);

        std::string text = dataSerie.m_title + " - " + value + " (" + percent + ")";
        Font::show_text(m_renderer, text, 16, Color::Black, 16*i, 40);
        i++;
    }
}

void PieGraph::draw_pie_chart(float startAngle, float endAngle, int radius)
{
    int segments = 2 * radius * (endAngle - startAngle);
    for (int i = 0; i <= segments; ++i) 
    {
        float t = static_cast<float>(i) / segments;
        float currentAngle = startAngle + t * (endAngle - startAngle);
        int x = m_width/2 + radius * std::cos(currentAngle);
        int y = m_height/2 + radius * std::sin(currentAngle);
        SDL_RenderDrawLine(m_renderer, m_width/2, m_height/2, x, y);
        SDL_RenderDrawLine(m_renderer, m_width/2 + 1, m_height/2, x + 1, y);
    }
}
