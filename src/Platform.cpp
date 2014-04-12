#include "Platform.h"
#include <iostream>
#include <stdio.h>
 
Platform::Platform()
{
	x = 100;
	y = 350;
		
}
 
Platform::~Platform()
{
}



void Platform::setY(int speed)
{

	if(y <= floor && speed < 0)
		y += speed;
	else if(speed > 0 && y < floor)
	{
		y += speed;
	}
	else if (y > floor)
		y = floor;
		
	
}

void Platform::setX(int speed)
{
	x += speed;
}

int Platform::getX()
{
	return x;
}

int Platform::getY()
{
	return y;
}
 
void Platform::loadPlatform()
{
	platformBitmap = al_load_bitmap("./imgFiles/basicPlatform.png");
	imgWidth =  al_get_bitmap_width(platformBitmap);
	imgHeight = al_get_bitmap_height(platformBitmap);

	
}

void Platform::unloadPlatform()
{
	al_destroy_bitmap(platformBitmap);
}

void Platform::draw()
{
	if (true)
		al_draw_bitmap(platformBitmap, x, y, 0);
	else
		al_draw_bitmap(platformBitmap, x, y, ALLEGRO_FLIP_HORIZONTAL);

}
