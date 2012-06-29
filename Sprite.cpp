#include "Sprite.h"

namespace hm
{
	Sprite::Sprite()
	{
		image = NULL; // Safety.

		position.x = 0; // Default position.
		position.y = 0;
		selectSprite(0, 0); // Default sprite.
		setSpriteSize(0, 0); // Default sprite size.
	}

	Sprite::Sprite(std::string filename)
	{
		loadImage(filename);

		position.x = 0; // Default position.
		position.y = 0;
		selectSprite(0, 0); // Default sprite.
		setSpriteSize(0, 0); // Default sprite size.
	}

	Sprite::Sprite(std::string filename, int spriteWidth, int spriteHeight)
	{
		loadImage(filename);

		position.x = 0; // Default position.
		position.y = 0;
		selectSprite(0, 0); // Default sprite.
		setSpriteSize(spriteWidth + 1, spriteHeight + 1); // Set sprite size.
		recalc();
	}

	void Sprite::draw(SDL_Surface* surface)
	{
		SDL_BlitSurface(this->image, this->getSpriteClip(), surface, this->getPosition());
		return;
	}

	void Sprite::selectSprite(int x, int y)
	{
		spriteNumber.x = x;
		spriteNumber.y = y;
		recalc();
		return;
	}

	SDL_Rect* Sprite::getCurrentSprite()
	{
		return &spriteNumber;
	}

	void Sprite::nextSprite()
	{
		spriteNumber.x++;
		recalc();
		return;
	}

	void Sprite::prevSprite()
	{
		spriteNumber.x--;
		recalc();
		return;
	}

	void Sprite::reset()
	{
		spriteNumber.x = 0;
		return;
	}

	SDL_Rect* Sprite::getSpriteClip()
	{
		return &spriteClip;
	}

	void Sprite::setSpriteSize(SDL_Rect spriteSize)
	{
		this->spriteClip.w = spriteSize.w;
		this->spriteClip.h = spriteSize.h;
		recalc();

		return;
	}

	void Sprite::setSpriteSize(int width, int height)
	{
		spriteClip.w = width;
		spriteClip.h = height;
		recalc();

		return;
	}

	void Sprite::setSpacing(int w, int h)
	{
		spriteSpacing.w = w;
		spriteSpacing.h = h;

		return;
	}

	void Sprite::setOffset(int w, int h)
	{
		spriteOffset.w = w;
		spriteOffset.h = h;

		return;
	}

	void Sprite::recalc()
	{
		spriteClip.x = (spriteClip.w * spriteNumber.x) + (spriteSpacing.w * (spriteNumber.x + 1));
		spriteClip.y = (spriteClip.h * spriteNumber.y) + (spriteSpacing.h * (spriteNumber.y + 1));

		return;
	}
};