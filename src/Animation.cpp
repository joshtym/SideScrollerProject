#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::loadContent(ALLEGRO_BITMAP* givenImage, std::string givenText, double givenPosition[2])
{
	image = givenImage;
	text = givenText;
	position[0] = givenPosition[0];
	position[1] = givenPosition[1];
	
	alpha = 255;
	sourceRectangle = image;
	isActive = false;
	
	frameCount = std::pair<int, int>(3,4);
	currentFrame = std::pair<int, int>(1, 0);
}

void Animation::unloadContent()
{
	al_destroy_bitmap(image);
	al_destroy_bitmap(sourceRectangle);
	alpha = 0;
	position[0] = position[1] = 0;
}

void Animation::update(InputManagement input)
{
}

void Animation::draw(ALLEGRO_DISPLAY *display)
{
	if (sourceRectangle != 0)
		al_draw_tinted_bitmap(sourceRectangle, al_map_rgba(255, 255, 255, alpha), 
			position[0], position[1], 0);
	else if (image != 0)
		al_draw_tinted_bitmap(image, al_map_rgba(0, 0, 0, alpha), 
			position[0], position[1], 0);
}

void Animation::setAlpha(double givenInput)
{
	alpha = givenInput;
}

double Animation::getAlpha()
{
	return alpha;
}

void Animation::setIsActive(bool givenInput)
{
	isActive = givenInput;
}

bool Animation::getIsActive()
{
	return isActive;
}

std::pair<int, int> &Animation::modifiableFrameCount()
{
	return frameCount;
}

std::pair<int, int> &Animation::modifiableCurrentFrame()
{
	return currentFrame;
}

std::pair<int, int> &Animation::getFrameDimensions()
{
	std::pair<int, int> frameDimensions(al_get_bitmap_width(image) / frameCount.first,
		al_get_bitmap_height(image) / frameCount.second);
		
	return frameDimensions;
}

ALLEGRO_BITMAP* Animation::Image()
{
	return image;
}

ALLEGRO_BITMAP*& Animation::returnSourceRectangle()
{
	return sourceRectangle;
}
