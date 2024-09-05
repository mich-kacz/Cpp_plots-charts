/**
 * @file graph.hpp
 * @author Mateusz Braszczok, Michał Kaczmarczyk
 * @brief Base graph class
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GRAPH_HPP_INCLUDED__
#define GRAPH_HPP_INCLUDED__

#include "window.hpp"
#include "dataSerie.hpp"
#include <string>
#include <vector>

/**
 * @brief Graph class.
 * 
 */
class Graph : public Window
{
public:
    /**
     * @brief Construct a new Graph object
     * 
     */
    Graph();

    /**
     * @brief Destroy the Graph object
     * 
     */
    virtual ~Graph(){};

    /**
     * @brief Add new data serie to existing graph
     * 
     * @param dataSerie New data serie
     */
    virtual void add_data_serie(const DataSerie &dataSerie);

    /**
     * @brief Set the new title of graph
     * 
     * @param title New graph title
     */
    void set_title(const std::string& title);

private:
    static unsigned int id;

protected:
    std::string m_title;
    std::vector<DataSerie> m_dataSeries;
};

#endif