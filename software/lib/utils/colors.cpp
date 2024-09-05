/**
 * @file colors.cpp
 * @author Mateusz Braszczok, Michał Kaczmarczyk
 * @brief Implementation of function which set color
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "colors.hpp"

void Colors::set_color(SDL_Renderer* const renderer, Color color)
{
    switch (color)
    {
        case White:
            SDL_SetRenderDrawColor(renderer, 215, 215 ,215, 215);
            break;
        case Red:
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            break;
        case Green:
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            break;
        case Blue:
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            break;
        case Black:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            break;
        case Yellow:
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            break;
        case Magenta:
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            break;
        case Cyan:
            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
            break;
        default:
            break;
    }
}