/**
 * @file columnGraph.hpp
 * @author Mateusz Braszczok, Michał Kaczmarczyk
 * @brief Column graph class.
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COLUMN_GRAPH_HPP_INCLUDED__
#define COLUMN_GRAPH_HPP_INCLUDED__

#include "graph.hpp"

/**
 * @brief Column graph class.
 * 
 */
class ColumnGraph : public Graph
{
public:
    /**
     * @brief Construct a new Column Graph object
     * 
     * @param title Title of new column graph
     */
    ColumnGraph(const std::string &title = "Column graph");

    /**
     * @brief Construct a new Column Graph object
     * 
     * @param dataSeries Vector data series
     * @param title Title of new column graph
     */
    ColumnGraph(const std::vector<DataSerie> &dataSeries, const std::string &title = "Column graph");

    /**
     * @brief Destroy the Column Graph object
     * 
     */
    ~ColumnGraph() = default;

    /**
     * @brief Add to existing object new data serie
     * 
     * @param dataSerie New data serie
     */
    void add_data_serie(const DataSerie &dataSerie) override;

private:
    void calculate_max();
    void draw_legend();

    double m_maxValue;

protected:
    void draw() override;
};

#endif
