/**
 * @file font.hpp
 * @author Mateusz Braszczok, Michal Kaczmarczyk
 * @brief Struct with functions to render text
 * @version 0.1
 * @date 2023-06-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FONT_HPP_INCLUDED__
#define FONT_HPP_INCLUDED__

#include "colors.hpp"

#include <string>
#include <SDL2/SDL.h>

/**
 * @brief Font structure
 * 
 */
struct Font
{
    /**
     * @brief Method render given text
     * 
     * @param renderer pointer to SDL_Renderer object
     * @param text text to show
     * @param font_size font size of text
     * @param color color of text
     * @param v_pos vertical position of text (in pixels)
     * @param h_pos horizontal position of text (in pixels)
     * @param centered is text centered
     * @param bold is text bold
     */
    static void show_text(SDL_Renderer* const renderer, const std::string &text, unsigned int font_size, Color color, unsigned int v_pos, unsigned int h_pos, bool centered=false, bool bold=false);
};

#endif