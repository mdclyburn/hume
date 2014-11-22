#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

#include "Blittable.h"

namespace hm
{
	class Animation
	{
		public:
			Animation();
			~Animation();

			void add(const Blittable& b);
			void remove(const Blittable& b);

			virtual void animate() = 0;

		protected:
			std::vector<Blittable*> targets;
	}
}

#endif
