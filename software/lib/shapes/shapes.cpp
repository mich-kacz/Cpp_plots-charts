/**
 * @file shapes.cpp
 * @author Mateusz Braszczok, Michal Kaczmarczyk
 * @brief Implementation of functions to create graphical shapes
 * @version 0.1
 * @date 2023-06-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "shapes.hpp"

void Shapes::draw_rectangle(SDL_Renderer* renderer, int x, int y, int width, int height, Color color)
{
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = width;
    rectangle.h = height;

    Colors::set_color(renderer,color);
    SDL_RenderFillRect(renderer, &rectangle);
}

void Shapes::draw_circle(SDL_Renderer *renderer, int x, int y, int radius, Color color)
{
    Colors::set_color(renderer, color);
    for (int w = 0; w <= radius * 2; w++)
    {
        for (int h = 0; h <= radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void Shapes::draw_line(SDL_Renderer *renderer, int start_x, int start_y, int end_x, int end_y, Color color)
{
    Colors::set_color(renderer, color);
    SDL_RenderDrawLine(renderer, start_x, start_y, end_x, end_y);
}