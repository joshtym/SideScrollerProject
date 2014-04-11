#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
	frameCounter = 0;
	switchFrame = 100;
}

SpriteSheet::~SpriteSheet()
{
}

void SpriteSheet::update(Animation& currentAnimation)
{
	if (currentAnimation.getIsActive())
	{
		frameCounter++;
		
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			currentAnimation.modifiableCurrentFrame().first++;
			
			if (currentAnimation.modifiableCurrentFrame().first * 
				currentAnimation.modifiableFrameCount().first >= 
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
