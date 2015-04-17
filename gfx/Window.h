#ifndef WINDOW_H
#define WINDOW_H

#include "Blittable.h"
#include "Properties.h"
#include "WindowSettings.h"

class Window
{
public:
    Window();
    virtual ~Window();

    void create();
    void destroy();

    void apply(WindowSettings& w);

    WindowSettings get_settings() const;
    SDL_Window* get_window();
    SDL_Renderer* get_renderer();

    void draw(const Blittable* const b, const Properties& p);
    void present();
    void clear();

protected:
    SDL_Window* window;
    SDL_Renderer* renderer;
    WindowSettings settings;
};

#endif
