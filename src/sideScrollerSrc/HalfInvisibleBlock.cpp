#include "HalfInvisibleBlock.h"
 
HalfInvisibleBlock::HalfInvisibleBlock()
{
	// Assign default values
	scrollerObstacleDimension.setMinX(802);
	scrollerObstacleDimension.setMinY(250 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	isDeadly = false;
	isBeingDrawn = false;
}
 
HalfInvisibleBlock::~HalfInvisibleBlock()
{
}
 
void HalfInvisibleBlock::loadScrollerObstacle()
{
	// Load bitmap
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/computer1.png");
	
	// Set image width and height
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	// Update scroller values accordingly
	scrollerObstacleDimension.updateValues();
}
