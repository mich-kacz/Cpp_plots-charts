#include "graph.hpp"

unsigned int Graph::id = 0;

Graph::Graph() : Window("Figure " + std::to_string(++id))
{
}

void Graph::add_data_serie(const DataSerie &dataSerie)
{
    m_dataSeries.push_back(dataSerie);
    draw();
}

void Graph::set_title(const std::string& title)
{
    m_title = title;
    draw();
}