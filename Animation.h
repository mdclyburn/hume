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

			void setAnimationSpeed(const int units);

			virtual void animate();
			bool isComplete();

		protected:
			int units;
			std::vector<Blittable*> targets;
	};
}

#endif
