#ifndef ANIMATIONQUEUE_H
#define ANIMATIONQUEUE_H

#include <queue>

#include "Animation.h"

namespace hm
{
	class AnimationQueue
	{
		public:
			AnimationQueue();
			~AnimationQueue();

			void enqueue(Animation a);
			void animate();
			bool isComplete();

		protected:
			std::queue<Animation> animationQueue;
	};
}

#endif
