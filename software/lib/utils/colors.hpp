/**
 * @file colors.hpp
 * @author Mateusz Braszczok, Michał Kaczmarczyk
 * @brief Struct with function to set color of graphical elements
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COLORS_HPP_INCLUDED__
#define COLORS_HPP_INCLUDED__

#include <SDL2/SDL.h>

/**
 * @brief Enum with possible colors to set
 * 
 */
enum Color
{
    White,
    Red,
    Green,
    Blue,
    Black,
    Yellow,
    Magenta,
    Cyan
};

/**
 * @brief Colors structure
 * 
 */
struct Colors
{
    /**
     * @brief Method set current color
     * 
     * @param renderer Pointer to SDL_Renderer object
     * @param color Color enum value to set
     */
    static void set_color(SDL_Renderer* const renderer, Color color);
};

#endif