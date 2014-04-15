#include <iostream>
#include <stdio.h>
#include "SmallBlock.h"
 
SmallBlock::SmallBlock()
{
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(200 + rand() % 188);
	isDeadly = false;
	isBeingDrawn = false;
}
 
SmallBlock::~SmallBlock()
{
}
 
void SmallBlock::loadScrollerObstacle()
{
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/block.png");
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	scrollerObstacleDimension.updateValues();
	
}
