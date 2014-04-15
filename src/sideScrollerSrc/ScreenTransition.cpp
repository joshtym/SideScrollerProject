#include "ScreenTransition.h"

ScreenTransition::ScreenTransition()
{
	transitionSpeed = 5;
	increase = false;
}

ScreenTransition::~ScreenTransition()
{
}

void ScreenTransition::update(Animation& currentAnimation)
{
	if (currentAnimation.getIsActive())
	{
		if (!increase)
			currentAnimation.getAlpha() -= transitionSpeed;
		else
			currentAnimation.getAlpha() += transitionSpeed;
			
		if (currentAnimation.getAlpha() <= 0)
		{
			currentAnimation.getAlpha() = 0;
			increase = true;
		}
		else if (currentAnimation.getAlpha() >= 255)
		{
			currentAnimation.getAlpha() = 255;
			increase = false;
		}
	}
	else
		currentAnimation.getAlpha() = 255;
}

void ScreenTransition::setIncrease(bool givenInput)
{
	increase = givenInput;
}
