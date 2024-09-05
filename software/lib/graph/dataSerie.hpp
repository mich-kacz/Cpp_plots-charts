/**
 * @file dataSerie.hpp
 * @author Mateusz Braszczok, Michał Kaczmarczyk
 * @brief Data Series struct.
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef DATA_SERIE_HPP_INCLUDED__
#define DATA_SERIE_HPP_INCLUDED__

#include <string>
#include <vector>
#include <map>
#include "colors.hpp"

/**
 * @brief DataSerie struct.
 * 
 */
struct DataSerie
{
public:
    /**
     * @brief Construct a new Data Serie object
     * 
     * @param points Vector of points
     * @param color Enum color value of data serie
     * @param title Title of data serie
     */
    DataSerie(const std::vector<std::pair<double, double>> &points, Color color, const std::string &title = "Serie");

    /**
     * @brief Construct a new Data Serie object
     * 
     * @param x Single value
     * @param color Enum color value of data serie
     * @param title Title of data serie
     */
    DataSerie(double x, Color color, const std::string &title = "Serie");

    /**
     * @brief Title of data serie
     * 
     */
    std::string m_title;

    /**
     * @brief Single value
     * 
     */
    double m_value;

    /**
     * @brief Vector of points
     * 
     */
    std::vector<std::pair<double, double>> m_points;

    /**
     * @brief Enum color value of data serie
     * 
     */
    Color m_color;
};

#endif
