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

			virtual void animate() = 0;

		protected:
			std::vector<Blittable*> targets;
	};
}

#endif
