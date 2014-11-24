#include "AnimationQueue.h"

namespace hm
{
	AnimationQueue::AnimationQueue()
	{
	
	}

	AnimationQueue::~AnimationQueue()
	{
	
	}

	void AnimationQueue::enqueue(Animation a)
	{
		animationQueue.push(a);
		return;	
	}

	void AnimationQueue::animate()
	{
		if(animationQueue.empty()) return;

		animationQueue.front().animate();
		if(animationQueue.front().isComplete())
			animationQueue.pop();

		return;
	}

	bool AnimationQueue::isComplete()
	{
		return animationQueue.empty();
	}
}
