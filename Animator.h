#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <vector>

#include "Animation.h"
#include "AnimationQueue.h"

namespace hm
{
	class Animator
	{
		public:
			Animator();
			~Animator();

			void add(Animation a);
			void add(AnimationQueue q);
			void clearAnimations();
			void clearQueues();
			void clear();

			void animate();

		protected:
			std::vector<Animation> animations;
			std::vector<AnimationQueue> queues;
	};
}

#endif
