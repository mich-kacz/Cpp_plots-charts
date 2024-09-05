#include "linearGraph.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <cmath>
#include <sstream>

#include "shapes.hpp"
#include "font.hpp"

LinearGraph::LinearGraph(const std::string &title)
{
    m_title = title;
    Window::update();
}

LinearGraph::LinearGraph(const std::vector<DataSerie> &dataSeries, const std::string &title)
{
    m_dataSeries = dataSeries;
    m_title = title;
    find_min_max();
    draw();
}

void LinearGraph::add_data_serie(const DataSerie &dataSerie)
{
    Graph::add_data_serie(dataSerie);
    find_min_max();
}

void LinearGraph::add_point_to_data_serie(const std::string &dataSerieLabel, const std::pair<double, double> &point)
{
    for (auto &dataSerie : m_dataSeries)
    {
        if (dataSerie.m_title == dataSerieLabel)
        {
            dataSerie.m_points.push_back(point);
            find_min_max();
            break;
        }
    }
    draw();
}

void LinearGraph::set_x_label(const std::string &x_label)
{
    m_xLabel = x_label;
    draw();
}

void LinearGraph::set_y_label(const std::string &y_label)
{
    m_yLabel = y_label;
    draw();
}

void LinearGraph::draw()
{
    Window::clear();
    draw_axis();
    draw_data();
    draw_interpolate_points();
    draw_stamples();
    Window::update();
}

void LinearGraph::draw_axis()
{
    Shapes::draw_rectangle(m_renderer, m_width / 10, m_height / 2 + m_height / 400, m_width - 2 * m_width / 10, m_height / 200);                                                 // horizontal
    Shapes::draw_rectangle(m_renderer, m_width / 2 - m_height / 400, m_height / 10, m_height / 200, m_height - 2 * m_height / 10);                                               // vertical
    Shapes::draw_rectangle(m_renderer, m_width - m_width / 10 - m_height / 50, m_height / 2 - m_height / 100, m_height / 100, m_height / 50 + m_height / 100);                       // arrow11
    Shapes::draw_rectangle(m_renderer, m_width - m_width / 10 - m_height / 75, m_height / 2 - m_height / 170, m_height / 100, m_height / 85 + m_height / 100);                       // arrow12
    Shapes::draw_rectangle(m_renderer, m_width / 2 - m_height / 100 - m_height / 200, m_height / 10 + m_height / 50 - m_height / 100, m_height / 50 + m_height / 100, m_height / 100); // arrow21
    Shapes::draw_rectangle(m_renderer, m_width / 2 - m_height / 170 - m_height / 200, m_height / 10 + m_height / 75 - m_height / 100, m_height / 85 + m_height / 100, m_height / 100); // arrow22

    if (!m_xLabel.empty())
    {
        Font::show_text(m_renderer, m_xLabel, m_height / 30, Color::Black, m_height / 2 + 1 - m_height / 200, m_width - m_width / 10);
    }

    if (!m_yLabel.empty())
    {
        Font::show_text(m_renderer, m_yLabel, m_height / 30, Color::Black, m_height / 10, m_width / 2 + 1 + 4 * m_height / 200);
    }

    if (!m_title.empty())
    {
        Font::show_text(m_renderer, m_title, m_height / 30, Color::Black, m_height / 100, (m_width / 2), true, true);
    }
    m_beginX = m_width / 10;
    m_beginY = m_height - m_height / 10;
    m_endX = m_width - m_width / 10;
    m_endY = m_height / 10;
}

void LinearGraph::find_min_max()
{
    m_maxXValue = std::numeric_limits<double>::lowest();
    m_maxYValue = std::numeric_limits<double>::lowest();
    m_minXValue = std::numeric_limits<double>::max();
    m_minYValue = std::numeric_limits<double>::max();

    double max_x, min_x, max_y, min_y;
    for (const auto &dataSerie : m_dataSeries)
    {
        auto min_max_first = std::minmax_element(dataSerie.m_points.begin(), dataSerie.m_points.end(),
            [](const auto& pair1, const auto& pair2) {
                return pair1.first < pair2.first;
            }
        );

        auto min_max_second = std::minmax_element(dataSerie.m_points.begin(), dataSerie.m_points.end(),
            [](const auto& pair1, const auto& pair2) {
                return pair1.second < pair2.second;
            }
        );

        min_x = min_max_first.first->first;
        max_x = min_max_first.second->first;
        min_y = min_max_second.first->second;
        max_y = min_max_second.second->second;

        m_minXValue = (min_x < m_minXValue) ? min_x : m_minXValue;
        m_maxXValue = (max_x > m_maxXValue) ? max_x : m_maxXValue;
        m_minYValue = (min_y < m_minYValue) ? min_y : m_minYValue;
        m_maxYValue = (max_y > m_maxYValue) ? max_y : m_maxYValue;
    }

    std::cout << "min_x: " << m_minXValue << "\tmax_x: " << m_maxXValue << "\tmin_y: " << m_minYValue << "\tmax_y: " << m_maxYValue << std::endl;
}

void LinearGraph::scale(double &x, double &y)
{
    unsigned int midW = (m_endX + m_beginX) / 2;
    unsigned int midH = (m_beginY + m_endY) / 2;
    unsigned int rangeX = m_endX - midW;
    unsigned int rangeY = m_beginY - midH;

    double scaleX = (abs(m_maxXValue) > abs(m_minXValue)) ? (x * rangeX) / abs(m_maxXValue) : (x * rangeX) / abs(m_minXValue);
    double scaleY = (abs(m_maxYValue) > abs(m_minYValue)) ? (y * rangeY) / abs(m_maxYValue) : (y * rangeY) / abs(m_minYValue);

    x = midW + scaleX;
    y = midH - scaleY;
}

void LinearGraph::draw_stamples()
{
    double x = 0, y = 0, max;

    std::ostringstream out;

    max = (abs(m_maxXValue) > abs(m_minXValue)) ? abs(m_maxXValue) : abs(m_minXValue);

    for (double i = max / 10; i < max - max / 10; i += max / 10)
    {
        x = i;
        scale(x, y);
        out << i;
        Font::show_text(m_renderer, out.str(), m_height / 50, Color::Black, (m_beginY + m_endY) / 2, x);
        out.str("");
        x = -i;
        scale(x, y);
        out << -i;
        Font::show_text(m_renderer, out.str(), m_height / 50, Color::Black, (m_beginY + m_endY) / 2, x);
        out.str("");
    }

    max = (abs(m_maxYValue) > abs(m_minYValue)) ? abs(m_maxYValue) : abs(m_minYValue);
    for (double i = max / 10; i < max - max / 10; i += max / 10)
    {
        y = i;
        scale(x, y);
        out << i;
        Font::show_text(m_renderer, out.str(), m_height / 50, Color::Black, y, (m_endX + m_beginX) / 1.98);
        out.str("");
        y = -i;
        scale(x, y);
        out << -i;
        Font::show_text(m_renderer, out.str(), m_height / 50, Color::Black, y, (m_endX + m_beginX) / 1.98);
        out.str("");
    }
}

void LinearGraph::draw_data()
{
    double x, y;
    for (const auto &dataSerie : m_dataSeries)
    {
        auto it = dataSerie.m_points.begin();
        for (auto it = dataSerie.m_points.begin(); it != dataSerie.m_points.end(); it++)
        {
            x = it->first;
            y = it->second;
            scale(x, y);
            Shapes::draw_circle(m_renderer, x, y, 4, dataSerie.m_color);
        }
    }
}

void LinearGraph::draw_interpolate_points()
{
    double x1, x2, y1, y2;
    for (const auto &dataSerie : m_dataSeries)
    {
        Colors::set_color(m_renderer, dataSerie.m_color);
        for (auto it = dataSerie.m_points.begin(); std::next(it) != dataSerie.m_points.end(); it++)
        {
            x1 = it->first;
            y1 = it->second;
            x2 = std::next(it)->first;
            y2 = std::next(it)->second;
            scale(x1, y1);
            scale(x2, y2);
            for (int i = 0; i < m_lineWidth; i++)
            {
                if (i % 2 == 0)
                {
                    if (abs(x1 - x2) > abs(y1 - y2))
                    {
                        Shapes::draw_line(m_renderer, x1 + i, y1, x2 + i, y2, dataSerie.m_color);
                    }
                    else
                    {
                        Shapes::draw_line(m_renderer, x1, y1 + i, x2, y2 + i, dataSerie.m_color);
                    }
                }
                else
                {
                    if (abs(x1 - x2) > abs(y1 - y2))
                    {
                        Shapes::draw_line(m_renderer, x1 - i, y1, x2 - i, y2, dataSerie.m_color);
                    }
                    else
                    {
                        Shapes::draw_line(m_renderer, x1, y1 - i, x2, y2 - i, dataSerie.m_color);
                    }
                }
            }
        }
    }
}