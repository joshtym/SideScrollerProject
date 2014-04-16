#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
	frameCounter = 0;
	switchFrame = 10;
}

SpriteSheet::~SpriteSheet()
{
}

void SpriteSheet::update(Animation& currentAnimation)
{
	// Deals with updating the sprite animation dependent on time
	// values and switch frames, and activity
	if (currentAnimation.getIsActive())
	{
		frameCounter++;
		
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			currentAnimation.modifiableCurrentFrame().first++;
			
			if (currentAnimation.modifiableCurrentFrame().first * 
				currentAnimation.getFrameDimensions().first >= 
				al_get_bitmap_width(currentAnimation.Image()))
			{
				currentAnimation.modifiableCurrentFrame().first = 0;
			}
		}
	}
	else
	{
		frameCounter = 0;
		currentAnimation.modifiableCurrentFrame().first = 1;
	}
	
	currentAnimation.returnSourceRectangle() = 
		al_create_sub_bitmap(currentAnimation.Image(), 
			currentAnimation.modifiableCurrentFrame().first * 
			currentAnimation.getFrameDimensions().first, 
			currentAnimation.modifiableCurrentFrame().second * 
			currentAnimation.getFrameDimensions().second, 
			currentAnimation.getFrameDimensions().first, 
			currentAnimation.getFrameDimensions().second);
}
