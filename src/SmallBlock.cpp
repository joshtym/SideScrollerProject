#include <iostream>
#include <stdio.h>
#include "SmallBlock.h"
 
SmallBlock::SmallBlock()
{
	srand(time(0));
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % 200);
}
 
SmallBlock::~SmallBlock()
{
}
 
void SmallBlock::loadScrollerObstacle()
{
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/block.png");
	//platformBitmap2 = al_load_bitmap("./imgFiles/basicPlatformd.png");
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	scrollerObstacleDimension.updateValues();
	
}
