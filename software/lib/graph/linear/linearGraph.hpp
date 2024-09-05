/**
 * @file linearGraph.hpp
 * @author Mateusz Braszczok, Michał Kaczmarczyk
 * @brief Linear graph class.
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LINEAR_GRAPH_HPP_INCLUDED__
#define LINEAR_GRAPH_HPP_INCLUDED__

#include "graph.hpp"


/**
 * @brief Linear graph class
 * 
 */
class LinearGraph : public Graph
{
public:
    /**
     * @brief Construct a new Linear Graph object
     * 
     * @param title Title of new linear graph
     */
    LinearGraph(const std::string &title = "Linear graph");

    /**
     * @brief Construct a new Linear Graph object
     * 
     * @param dataSeries Vector data series
     * @param title Title of new column graph
     */
    LinearGraph(const std::vector<DataSerie> &dataSeries, const std::string &title = "Linear graph");

    /**
     * @brief Destroy the Linear Graph object
     * 
     */
    ~LinearGraph() = default;

    /**
     * @brief Add to existing object new data serie
     * 
     * @param dataSerie New data serie
     */
    void add_data_serie(const DataSerie &dataSerie) override;

    /**
     * @brief Add to existing data serie new point
     * 
     * @param dataSerieLabel Title of existing data serie
     * @param point Pair as a new point
     */
    void add_point_to_data_serie(const std::string &dataSerieLabel, const std::pair<double, double> &point);

    /**
     * @brief Set the x axis label
     * 
     * @param x_label X axis label
     */
    void set_x_label(const std::string& x_label);

    /**
     * @brief Set the y axis label
     * 
     * @param y_label Y axis label
     */
    void set_y_label(const std::string& y_label);

private:
    void draw_axis();
    void find_min_max();
    void scale(double &x, double &y);
    void draw_stamples();
    void draw_data();
    void draw_interpolate_points();
    std::string m_xLabel;
    std::string m_yLabel;

    double m_maxXValue, m_maxYValue;
    double m_minXValue, m_minYValue;
    unsigned int m_endX = 0, m_endY = 0, m_beginX = 0, m_beginY = 0;
    unsigned int m_lineWidth = 6;

protected:
    void draw() override;
};

#endif