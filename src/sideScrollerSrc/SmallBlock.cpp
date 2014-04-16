#include <iostream>
#include <stdio.h>
#include "SmallBlock.h"
 
SmallBlock::SmallBlock()
{
	// Assign default values
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	isDeadly = false;
	isBeingDrawn = false;
}
 
SmallBlock::~SmallBlock()
{
}
 
void SmallBlock::loadScrollerObstacle()
{
	// Load bitmap
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/block.png");
	
	// Assign imgWidth and imgHeight
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	// Update object dimensions accodringly
	scrollerObstacleDimension.updateValues();
	
}
