#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

#include "Blittable.h"
#include "Logger.h"

namespace hm
{
	class Animation
	{
		public:
			Animation();
			~Animation();

			void add(Blittable& b);
			void remove(Blittable& b);
			void removeAll();

			int getUnits();
			void setUnits(const int units);
			unsigned int getFrames();
			void setFrames(const unsigned int frames);

			void setAnimationSpeed(const int units, const unsigned int frames = 1);

			virtual void animate();
			virtual bool isComplete();

		protected:
			int units;
			unsigned int frames;

			std::vector<Blittable*> targets;
	};
}

#endif
