#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <vector>

#include "Animation.h"

namespace hm
{
	class Animator
	{
		public:
			Animator();
			~Animator();

			void add(Animation& a);
			void clear();

			void animate();

		protected:
			std::vector<Animation> animations;
	};
}

#endif
