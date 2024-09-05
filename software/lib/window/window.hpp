/**
 * @file window.hpp
 * @author Michal Kaczmarczyk, Mateusz Braszczok
 * @brief Base window class.
 * @version 0.1
 * @date 2023-06-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef WINDOW_HPP_INCLUDED__
#define WINDOW_HPP_INCLUDED__

#include <string>
#include <SDL2/SDL.h>
#include "colors.hpp"

/**
 * @brief Window class.
 *
 */
class Window
{
public:
    /**
     * @brief Construct a new Window object
     *
     * @param title - New window title
     * @param width - New window width, default = 640.
     * @param height  New window height, default = 480
     */
    Window(const std::string &title, int width = 640, int height = 480);
    /**
     * @brief Destroy the Window object
     *
     */
    ~Window();

    /**
     * @brief Get the window size
     *
     * @param width - int variable for width
     * @param height - int variable for height
     */
    void get_size(int &width, int &height);
    /**
     * @brief Update window state
     *
     */
    void update();
    /**
     * @brief Saves window as PNG image
     *
     * @param filename - name of image file
     * @return true
     * @return false
     */
    bool make_screenshot(const std::string &filename);
    /**
     * @brief Static method for keeping window alive on screen.
     * 
     */
    static void retainer();
    /**
     * @brief Static variable indicating if wndow should be closed.
     * 
     */
    static bool m_quit;

private:
    static int event_window_callback(void *data, SDL_Event *event);
    SDL_Window *m_window;
    Color m_backgroundColor = Color::White;

protected:
    SDL_Renderer *m_renderer;
    virtual void draw() = 0;
    void clear();
    void set_background_color();
    void set_background_color(Color color);
    int m_width, m_height;
};

#endif