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

void ScrollerObstacle::draw()
{
	al_draw_bitmap(scrollerObstacleBitmap, scrollerObstacleDimension.getMinX(), 
				   scrollerObstacleDimension.getMinY(), 0);
}

ObjectDimensions& ScrollerObstacle::getCurrentDimensions()
{
	return scrollerObstacleDimension;
}
