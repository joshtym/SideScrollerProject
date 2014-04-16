#include <cstdlib>
#include "ScrollerObstacle.h"

void ScrollerObstacle::unloadScrollerObstacle()
{
	// Destroy bitmap
	al_destroy_bitmap(scrollerObstacleBitmap);
}

void ScrollerObstacle::update(double ScrollerObstacleXValue)
{
	// Update the location of the object dependent on how far it is
	// down the screen
	scrollerObstacleDimension.setMinX(ScrollerObstacleXValue);
	scrollerObstacleDimension.updateValues();
}

void ScrollerObstacle::draw(double obstacleIncrementalValue)
{
	// Until the obstacle reaches the end of the screen, it is in a 
	// "being drawn" state. Draw the obstacle dependent on the incremental
	// value
	isBeingDrawn = true;
	
	scrollerObstacleDimension.setMinX(scrollerObstacleDimension.getMinX() - obstacleIncrementalValue);
	
	if (scrollerObstacleDimension.getMaxX() < 0)
	{
		isBeingDrawn = false;
		resetXAndYValues();
	}
	else
		al_draw_bitmap(scrollerObstacleBitmap, scrollerObstacleDimension.getMinX(), 
						scrollerObstacleDimension.getMinY(), 0);
						
	scrollerObstacleDimension.updateValues();
}

ObjectDimensions& ScrollerObstacle::getCurrentDimensions()
{
	return scrollerObstacleDimension;
}

bool ScrollerObstacle::getIsDeadly()
{
	return isDeadly;
}

bool ScrollerObstacle::getIsBeingDrawn()
{
	return isBeingDrawn;
}

void ScrollerObstacle::resetXAndYValues()
{
	scrollerObstacleDimension.setMinY(300 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	scrollerObstacleDimension.setMinX(800);
}
