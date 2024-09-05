/**
 * @file font.cpp
 * @author Mateusz Braszczok, Michal Kaczmarczyk
 * @brief Implementation of functions to render given text
 * @version 0.1
 * @date 2023-06-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "font.hpp"

#include <iostream>
#include <SDL2/SDL_ttf.h>

constexpr std::string_view regular_font = "software/lib/utils/fonts/open-sans/OpenSans-Regular.ttf";
constexpr std::string_view bold_font = "software/lib/utils/fonts/open-sans/OpenSans-Bold.ttf";

SDL_Color set_color(Color color)
{
    SDL_Color textColor = {0, 0, 0, 0};
    switch (color)
    {
        case White:
            textColor = {215, 215 ,215, 215};
            break;
        case Red:
            textColor = {255, 0, 0, 255};
            break;
        case Green:
            textColor = {0, 255, 0, 25};
            break;
        case Blue:
            textColor = {0, 0, 255, 255};
            break;
        case Black:
            textColor = {0, 0, 0, 255};
            break;
        case Yellow:
            textColor = {255, 255, 0, 255};
            break;
        case Magenta:
            textColor = {255, 0, 255, 255};
            break;
        case Cyan:
            textColor = {0, 255, 255, 255};
            break;
        default:
            break;
    }

    return textColor;
}


void Font::show_text(SDL_Renderer* const renderer, const std::string &text, unsigned int font_size, Color color, unsigned int v_pos, unsigned int h_pos, bool centered, bool bold)
{
    TTF_Init();

    TTF_Font* font = nullptr;
    if (bold)
    {
        font = TTF_OpenFont(bold_font.data(), font_size);
    }
    else
    {
        font = TTF_OpenFont(regular_font.data(), font_size);
    }

    if (font == nullptr)
    {
        std::cout << "Failed to load font" << std::endl;
    }

    SDL_Color textColor = set_color(color);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    if (textSurface == nullptr)
    {
        std::cout << "Failed to load surface" << std::endl;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == nullptr)
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    SDL_Rect textRect;
    textRect.y = v_pos;
    textRect.h = textSurface->h;
    if (centered)
    {
        textRect.x = h_pos - (textSurface->w) / 2;
    }
    else
    {
        textRect.x = h_pos;
    }
    textRect.w = textSurface->w;

    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
}
