/**
 * @file pieGraph.hpp
 * @author Mateusz Braszczok, Michał Kaczmarczyk
 * @brief Pie graph class.
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PIE_GRAPH_HPP_INCLUDED__
#define PIE_GRAPH_HPP_INCLUDED__

#include "graph.hpp"

/**
 * @brief Pie graph class.
 * 
 */
class PieGraph : public Graph
{
public:
    /**
     * @brief Construct a new Pie Graph object
     * 
     * @param title Title of new pie graph
     */
    PieGraph(const std::string &title = "Pie graph");

    /**
     * @brief Construct a new Pie Graph object
     * 
     * @param dataSeries Vector data series
     * @param title Title of new pie graph
     */
    PieGraph(const std::vector<DataSerie> &dataSeries, const std::string &title = "Pie graph");

    /**
     * @brief Destroy the Pie Graph object
     * 
     */
    ~PieGraph() = default;

    /**
     * @brief Add to existing object new data serie
     * 
     * @param dataSerie New data serie
     */
    void add_data_serie(const DataSerie &dataSerie) override;

private:
    void draw_pie_chart(float startAngle, float endAngle, int radius);
    double calculate_sum();
    void draw_legend();

    double m_totalSum;

protected:
    void draw() override;
};

#endif