#include "dataSerie.hpp"
#include <numeric>

DataSerie::DataSerie(const std::vector<std::pair<double, double>> &points, Color color, const std::string &title)
{
    m_points = points;
    m_color = color;
    m_title = title;
}

DataSerie::DataSerie(double y, Color color, const std::string &title)
{
    m_value = y;
    m_color = color;
    m_title = title;
}