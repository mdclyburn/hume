#include "Animator.h"

namespace hm
{
	Animator::Animator()
	{
	
	}

	Animator::~Animator()
	{
	
	}

	void Animator::add(Animation a)
	{
		animations.push_back(a);
		return;
	}

	void Animator::add(AnimationQueue q)
	{
		queues.push_back(q);
		return;
	}

	void Animator::clearAnimations()
	{
		animations.clear();
		return;
	}

	void Animator::clearQueues()
	{
		queues.clear();
		return;
	}

	void Animator::clear()
	{
		animations.clear();
		queues.clear();
		return;
	}

	void Animator::animate()
	{
		// Iteratively animate all given animations.
		for(std::vector<Animation>::iterator it = animations.begin();
				it != animations.end(); it++)
		{
			it->animate();

			// Remove completed animations.
			if(it->isComplete())
			{
				it = animations.erase(it);
				it--;
			}
		}

		// Iteratively animate all given queues.
		for(std::vector<AnimationQueue>::iterator it = queues.begin();
				it != queues.end(); it++)
		{
			it->animate();

			// Remove empty queues.
			if(it->isComplete())
			{
				it = animations.erase(it);
				it--;
			}
		}

		return;
	}
}
