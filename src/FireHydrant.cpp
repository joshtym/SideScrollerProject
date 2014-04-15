#include <iostream>
#include <stdio.h>
#include "FireHydrant.h"
 
FireHydrant::FireHydrant()
{
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	isDeadly = true;
	isBeingDrawn = false;
}
 
FireHydrant::~FireHydrant()
{
}
 
void FireHydrant::loadScrollerObstacle()
{
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/fire.png");
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	scrollerObstacleDimension.updateValues();
	
}
