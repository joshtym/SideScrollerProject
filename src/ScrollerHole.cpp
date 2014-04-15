#include "ScrollerHole.h"

ScrollerHole::ScrollerHole()
{
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
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/basicPlatformd1.png");
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	scrollerObstacleDimension.updateValues();
}
