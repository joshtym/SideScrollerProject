#include <iostream>
#include <stdio.h>
#include "HalfInvisibleBlock.h"
 
HalfInvisibleBlock::HalfInvisibleBlock()
{
	srand(time(0));
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % 200);
}
 
HalfInvisibleBlock::~HalfInvisibleBlock()
{
}
 
void HalfInvisibleBlock::loadScrollerObstacle()
{
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/HalfInvisPlatform.png");
	//platformBitmap2 = al_load_bitmap("./imgFiles/basicPlatformd.png");
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	scrollerObstacleDimension.updateValues();
	
}
