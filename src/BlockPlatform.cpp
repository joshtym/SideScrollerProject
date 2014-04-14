#include <iostream>
#include <stdio.h>
#include "BlockPlatform.h"
 
BlockPlatform::BlockPlatform()
{
	srand(time(0));
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % 200);
}
 
BlockPlatform::~BlockPlatform()
{
}
 
void BlockPlatform::loadScrollerObstacle()
{
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/basicPlatform1.png");
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	scrollerObstacleDimension.updateValues();
}
