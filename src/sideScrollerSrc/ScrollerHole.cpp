#include "ScrollerHole.h"

ScrollerHole::ScrollerHole()
{
	// Assign defaults
	isTransparent = true;
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(388);
	isDeadly = false;
	isBeingDrawn = false;
}

ScrollerHole::~ScrollerHole()
{
}

void ScrollerHole::loadScrollerObstacle()
{
	
	// Load bitmap
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/basicPlatformd1.png");
	
	// Set image height and width
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	// Update dimensions accordingly
	scrollerObstacleDimension.updateValues();
}
