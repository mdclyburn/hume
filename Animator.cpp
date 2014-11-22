#include "Animator.h"

namespace hm
{
	Animator::Animator()
	{
	
	}

	Animator::~Animator()
	{
	
	}

	void Animator::add(Animation& a)
	{
		animations.push_back(a);
		return;
	}

	void Animator::clear()
	{
		animations.clear();
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
				animations.erase(it);
		}

		return;
	}
}
