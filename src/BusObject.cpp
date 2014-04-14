#include <iostream>
#include <stdio.h>
#include "BusObject.h"
 
BusObject::BusObject()
{
	srand(time(0));
	platformDimension.setMinX(800);
	platformDimension.setMinY(250 + rand() % 200);
}
 
BusObject::~BusObject()
{
}
 
void BusObject::loadPlatform()
{
	platformBitmap = al_load_bitmap("./assets/imgFiles/basicPlatform.png");
	platformDimension.setImgWidth(al_get_bitmap_width(platformBitmap));
	platformDimension.setImgHeight(al_get_bitmap_height(platformBitmap));
	
	platformDimension.updateValues();
}
