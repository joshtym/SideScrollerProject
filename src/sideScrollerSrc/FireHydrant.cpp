#include "FireHydrant.h"
 
FireHydrant::FireHydrant()
{
	// Assign defaults
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	isDeadly = false;
	isBeingDrawn = false;
}
 
FireHydrant::~FireHydrant()
{
}
 
void FireHydrant::loadScrollerObstacle()
{
	// Load bitmap
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/fire.png");
	
	// Set object imgwidth and height accordingly
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	// Update values accordingly
	scrollerObstacleDimension.updateValues();
	
}
