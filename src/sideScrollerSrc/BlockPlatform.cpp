#include "BlockPlatform.h"
 
BlockPlatform::BlockPlatform()
{
	// Create defaults
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	isDeadly = false;
	isBeingDrawn = false;
}
 
BlockPlatform::~BlockPlatform()
{
}
 
void BlockPlatform::loadScrollerObstacle()
{
	// Load in bitmap
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/basicPlatform1.png");
	
	// Assign object dimension imgWidth and height
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	// Update all object dimensions accordingly
	scrollerObstacleDimension.updateValues();
}
