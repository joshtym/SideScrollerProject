#include "Platform.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Platform::unloadPlatform()
{
	al_destroy_bitmap(platformBitmap);
}

void Platform::update(double platformXValue)
{
	platformDimension.setMinX(platformXValue);
	platformDimension.updateValues();
}

void Platform::draw()
{
	al_draw_bitmap(platformBitmap, platformDimension.getMinX(), 
				   platformDimension.getMinY(), 0);

	al_draw_bitmap(platformBitmap2, platformDimension.getMinX(), 
				   platformDimension.getMinY()+50, 0);
	
}

ObjectDimensions& Platform::getCurrentDimensions()
{
	return platformDimension;
}
