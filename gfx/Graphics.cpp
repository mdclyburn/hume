#include "Graphics.h"

Graphics::Graphics() : window(nullptr)
{
}

Graphics::~Graphics()
{
    if(window) delete window;
}

void Graphics::initialize()
{
    const int types = IMG_INIT_JPG | IMG_INIT_PNG;
    const int result = IMG_Init(types);

    return;
}

void Graphics::shutdown()
{
    IMG_Quit();
    return;
}

void Graphics::set_window(Window* const w)
{
    window = w;
    return;
}

Image* Graphics::load_image(const std::string& filename)
{
    Image* image = new Image();
    image->open(filename, window->get_renderer());

    return image;
}

Image* Graphics::load_image(const std::string& filename, const Uint8 r, const Uint8 g, const Uint8 b)
{
    Image* image = new Image(r, g, b);
    image->open(filename, window->get_renderer());

    return image;
}

void Graphics::draw(const Blittable* const b, const Properties& p)
{
    window->draw(b, p);
    return;
}

void Graphics::clear()
{
	window->clear();
	return;
}

void Graphics::refresh()
{
    window->present();
    return;
}
