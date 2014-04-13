#include "Platform.h"
#include <iostream>
#include <stdio.h>
 
Platform::Platform()
{
	platformDimension.setMinX(800);
	platformDimension.setMinY(325);
}
 
Platform::~Platform()
{
}
 
void Platform::loadPlatform()
{
	platformBitmap = al_load_bitmap("./imgFiles/basicPlatform1.png");
	platformDimension.setImgWidth(al_get_bitmap_width(platformBitmap));
	platformDimension.setImgHeight(al_get_bitmap_height(platformBitmap));
	
	platformDimension.updateValues();
}

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
}

ObjectDimensions& Platform::getCurrentDimensions()
{
	return platformDimension;
}
