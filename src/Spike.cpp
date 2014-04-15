#include <iostream>
#include <stdio.h>
#include "Spike.h"
 
Spike::Spike()
{
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(200 + rand() % 188);
	isDeadly = true;
	isBeingDrawn = false;
}
 
Spike::~Spike()
{
}
 
void Spike::loadScrollerObstacle()
{
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/spikes.png");
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	scrollerObstacleDimension.updateValues();
	
}
