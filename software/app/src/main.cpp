/**
 * @file main.cpp
 * @author Mateusz Braszczok, Michał Kaczmarczyk
 * @brief Main program loop
 * @version 0.1
 * @date 2023-05-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#include "shapes.hpp"
#include "window.hpp"
#include "column/columnGraph.hpp"
#include "linear/linearGraph.hpp"
#include "pie/pieGraph.hpp"

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

int main()
{
    std::vector<std::pair<double, double>> cosPoints, sinPoints;

    for (int i = -50; i <= 50; i++)
    {
        sinPoints.push_back(std::make_pair(i, sin(2 * M_PI * i / 50)));
        cosPoints.push_back(std::make_pair(i, cos(2 * M_PI * i / 50)));
    }

    std::vector<DataSerie> dataSeries;
    dataSeries.push_back(DataSerie(sinPoints, Color::Blue, "sinus"));
    dataSeries.push_back(DataSerie(cosPoints, Color::Red, "cosinus"));

    std::string title = "Sinus 1 Hz, Tp = 0.02 s";
    LinearGraph lineGraph(dataSeries, title);

    std::string yLabel = "signal value";
    lineGraph.set_y_label(yLabel);

    std::string xLabel = "Sample Nb.";
    lineGraph.set_x_label(xLabel);

    lineGraph.add_point_to_data_serie("sinus", std::make_pair(100,10));
    lineGraph.add_point_to_data_serie("cosinus", std::make_pair(100,-10));

    PieGraph pieGraph("Number of fruits");
    ColumnGraph columnGraph("Number of fruits");
    DataSerie serie = DataSerie(12, Color::Red, "Apples");
    pieGraph.add_data_serie(serie);
    columnGraph.add_data_serie(serie);
    serie = DataSerie(24, Color::Blue, "Bananas");
    pieGraph.add_data_serie(serie);
    columnGraph.add_data_serie(serie);
    serie = DataSerie(48, Color::Green, "Pears");
    pieGraph.add_data_serie(serie);
    columnGraph.add_data_serie(serie);
    serie = DataSerie(96, Color::Yellow, "Strawberries");
    pieGraph.add_data_serie(serie);
    columnGraph.add_data_serie(serie);
    
 
    lineGraph.retainer();
    // std::string filename = "screenshot.png";
    // if (!pieGraph.make_screenshot(filename))
    // {
    //    std::cout << "Failed to save screenshot." << std::endl;
    // }

    return 0;
}
