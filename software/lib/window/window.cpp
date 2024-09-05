/**
 * @file window.cpp
 * @author Michal Kaczmarczyk, Mateusz Braszczok
 * @brief Base window class. 
 * @version 0.1
 * @date 2023-06-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "window.hpp"

#include <iostream>
#include <SDL2/SDL_image.h>

// Public API

bool Window::m_quit = false;

Window::Window(const std::string &title, int width, int height) : m_width(width), m_height(height)
{
    m_window = SDL_CreateWindow(title.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                m_width, m_height, SDL_WINDOW_RESIZABLE);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    Colors::set_color(m_renderer, Color::White);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);

    SDL_AddEventWatch(event_window_callback, this);
}

Window::~Window()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Window::update()
{
    SDL_RenderPresent(m_renderer);
}

void Window::get_size(int &width, int &height)
{
    width = m_width;
    height = m_height;
}

bool Window::make_screenshot(const std::string &filename)
{
    bool isSuccess = false;
    do
    {
        SDL_Texture *texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, m_width, m_height);
        if (!texture)
        {
            std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
            break;
        }
        SDL_SetRenderTarget(m_renderer, texture);
        SDL_RenderCopy(m_renderer, SDL_GetRenderTarget(m_renderer), nullptr, nullptr);
        SDL_SetRenderTarget(m_renderer, nullptr);

        SDL_Surface *surface = SDL_CreateRGBSurface(0, m_width, m_height, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
        if (!surface)
        {
            std::cout << "Failed to create surface: " << SDL_GetError() << std::endl;
            SDL_DestroyTexture(texture);
            break;
        }

        if (SDL_RenderReadPixels(m_renderer, nullptr, surface->format->format, surface->pixels, surface->pitch) != 0)
        {
            std::cout << "Failed to read pixels from renderer: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
            break;
        }

        SDL_Surface *convertedSurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA8888, 0);
        if (!convertedSurface)
        {
            std::cout << "Failed to convert surface format: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
            break;
        }

        if (IMG_SavePNG(convertedSurface, filename.c_str()) != 0)
        {
            std::cout << "Failed to save image to file: " << IMG_GetError() << std::endl;
            SDL_FreeSurface(convertedSurface);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
            break;
        }

        SDL_FreeSurface(convertedSurface);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);

        std::cout << "Image saved to file: " << filename << std::endl;
        isSuccess = true;
    } while (false);

    return isSuccess;
}

// Protected

void Window::clear()
{
    Colors::set_color(m_renderer, Color::White);
    SDL_RenderClear(m_renderer);
    SDL_RenderClear(m_renderer);
}

void Window::set_background_color(Color color)
{
    m_backgroundColor = color;
    Colors::set_color(m_renderer, m_backgroundColor);
    SDL_RenderClear(m_renderer);
    update();
}

void Window::set_background_color()
{
    Colors::set_color(m_renderer, m_backgroundColor);
    SDL_RenderClear(m_renderer);
    update();
}

// Static methods

int Window::event_window_callback(void *data, SDL_Event *event)
{
    if (event->type == SDL_WINDOWEVENT)
    {
        if (event->window.event == SDL_WINDOWEVENT_RESIZED)
        {
            Window *windowPtr = static_cast<Window *>(data);
            SDL_GetWindowSize(windowPtr->m_window, &windowPtr->m_width, &windowPtr->m_height);
            windowPtr->set_background_color();
            windowPtr->draw();
        }
        else if (event->window.event == SDL_WINDOWEVENT_CLOSE)
        {
            Window::m_quit = true;
        }
        else if ((event->window.event == SDL_WINDOWEVENT_MOVED) || (event->window.event == SDL_WINDOWEVENT_EXPOSED))
        {
            Window *windowPtr = static_cast<Window *>(data);
            windowPtr->update();
        }
    }
    else if (event->type == SDL_QUIT)
    {
        Window::m_quit = true;
    }
    return 0;
}

void Window::retainer()
{
    SDL_Event event;
    while (!m_quit)
    {
        SDL_Delay(100);
        while (SDL_PollEvent(&event))
        {
        }
    }
}