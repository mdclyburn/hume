#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../core/Component.h"
#include "Image.h"
#include "Window.h"

class Graphics : public Component
{
public:
    Graphics();
    virtual ~Graphics();

    virtual void initialize();
    virtual void shutdown();

    void set_window(Window* const w);

    Image* load_image(const std::string& filename);
    Image* load_image(const std::string& filename, const Uint8 r, const Uint8 g, const Uint8 b);

    void draw(const Blittable* const b, const Properties& p);
    void refresh();

protected:
    Window* window;
};

#endif
