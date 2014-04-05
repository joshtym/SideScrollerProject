#include "ScreenTransition.h"

ScreenTransition::ScreenTransition()
{
}

ScreenTransition::~ScreenTransition()
{
}

void ScreenTransition::loadContent(ALLEGRO_BITMAP* image, std::string text, double position[2])
{
	Animation::loadContent(image, text, position);
	transitionSpeed = 1;
	increase = false;
}

void ScreenTransition::unloadContent()
{
	Animation::unloadContent();
	transitionSpeed = 0;
}

void ScreenTransition::update(InputManagement input)
{
	if (isActive)
	{
		if (!increase)
			alpha -= transitionSpeed;
		else
			alpha += transitionSpeed;
			
		if (alpha <= 0)
		{
			alpha = 0;
			increase = true;
		}
		else if (alpha >= 255)
		{
			alpha = 255;
			increase = false;
		}
	}
	else
		alpha = 255;
}
