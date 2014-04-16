#include "BusObject.h"
 
BusObject::BusObject()
{
	// Assign defaults
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	isDeadly = false;
	isBeingDrawn = false;
}
 
BusObject::~BusObject()
{
}
 
void BusObject::loadScrollerObstacle()
{
	// Load up bitmap
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/basicPlatform.png");
	
	// Assign object dimension imgWidth and height
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	// Update object dimensions accordingly
	scrollerObstacleDimension.updateValues();
}
