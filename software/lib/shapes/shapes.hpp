/**
 * @file shapes.hpp
 * @author Mateusz Braszczok, Michal Kaczmarczyk
 * @brief Struct with functions to create graphical shapes
 * @version 0.1
 * @date 2023-06-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SHAPES_HPP_INCLUDED__
#define SHAPES_HPP_INCLUDED__

#include <SDL2/SDL.h>

#include "colors.hpp"

/**
 * @brief Shapes structure
 * 
 */
struct Shapes
{
    /**
     * @brief Method draws rectangle from origin at the upper left
     * 
     * @param renderer Pointer to SDL_Renderer object
     * @param x Starting horizontal value of rectangle (in pixels)
     * @param y Starting vertical value of rectangle (in pixels)
     * @param width Width of rectangle (in pixels)
     * @param height Height of rectangle (in pixels)
     * @param color Color of the rectangle
     */
    static void draw_rectangle(SDL_Renderer* renderer, int x, int y, int width, int height, Color color = Color::Black);

    /**
     * @brief Method draws circle from given the center of the circle and radius
     * 
     * @param renderer Pointer to SDL_Renderer object
     * @param x Horizontal value of the center of the circle (in pixels)
     * @param y Verical value of the center of the circle (in pixels)
     * @param radius Radius of circle (in pixels)
     * @param color Color of the circle
     */
    static void draw_circle(SDL_Renderer *renderer, int x, int y, int radius, Color color = Color::Black);

    /**
     * @brief Method draws line between two points
     * 
     * @param renderer Pointer to SDL_Renderer object
     * @param start_x Horizontal value of start point (in pixels)
     * @param start_y Vertical value of start point (in pixels)
     * @param end_x Horizontal value of end point (in pixels)
     * @param end_y Vertical value of end point (in pixels)
     * @param color Color of the line
     */
    static void draw_line(SDL_Renderer *renderer, int start_x, int start_y, int end_x, int end_y, Color color = Color::Black);
};

#endif