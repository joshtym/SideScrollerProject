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
	font = al_load_font("font1.ttf", 30, 0);
	sourceRectangle = image;
	isActive = false;
}

void Animation::unloadContent()
{
	al_destroy_bitmap(image);
	al_destroy_bitmap(sourceRectangle);
	al_destroy_font(font);
	alpha = 0;
	position[0] = position[1] = 0;
}

void Animation::update(InputManagement input)
{
}

void Animation::draw(ALLEGRO_DISPLAY *display)
{
	if (sourceRectangle != 0)
		al_draw_tinted_bitmap(sourceRectangle, al_map_rgba(0, 0, 0, alpha), 
			position[0], position[1], 0);
	else if (image != 0)
		al_draw_tinted_bitmap(image, al_map_rgba(0, 0, 0, alpha), 
			position[0], position[1], 0);
				
	if (text != "")
		al_draw_text(font, al_map_rgba(255, 0, 0, alpha), position[0],
			position[1], text.c_str());*/
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
