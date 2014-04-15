#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ScrollerObstacle.h"

void ScrollerObstacle::unloadScrollerObstacle()
{
	al_destroy_bitmap(scrollerObstacleBitmap);
}

void ScrollerObstacle::update(double ScrollerObstacleXValue)
{
	scrollerObstacleDimension.setMinX(ScrollerObstacleXValue);
	scrollerObstacleDimension.updateValues();
}

void ScrollerObstacle::draw(double obstacleIncrementalValue)
{
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
	scrollerObstacleDimension.setMinY(250 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	scrollerObstacleDimension.setMinX(800);
}
