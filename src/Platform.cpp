#include "Platform.h"
#include <iostream>
#include <stdio.h>
 
Platform::Platform()
{
	x = 100;
	y = 320;
	tdo = new TdObject();
}
 
Platform::~Platform()
{
	delete tdo;
}



void Platform::setY(int yin)
{

	y = yin;
		
	
}

void Platform::setX(int xin)
{
	x = xin;
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
	platformBitmap = al_load_bitmap("./imgFiles/basicPlatform1.png");
	imgWidth =  al_get_bitmap_width(platformBitmap);
	imgHeight = al_get_bitmap_height(platformBitmap);

	xWidth = imgWidth;
	yHeight = imgHeight;
	
	tdo->setX(x);
	tdo->setY(y);
	tdo->setYHeight(yHeight);
	tdo->setXWidth(xWidth);
	
	tdo->calcMixMax();
}

TdObject* Platform::getTdo()
{
	return tdo;
}

void Platform::unloadPlatform()
{
	al_destroy_bitmap(platformBitmap);
}

void Platform::draw()
{
	std::cout << tdo->getXWidth() << " " << tdo->getYHeight() << "\n";
	al_draw_bitmap(platformBitmap, x, y, 0);

}
