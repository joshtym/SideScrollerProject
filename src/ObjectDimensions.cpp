#include "ObjectDimensions.h"

ObjectDimensions::ObjectDimensions()
{
}

ObjectDimensions::~ObjectDimensions()
{
}

double ObjectDimensions::getMinX()
{
	return xMin;
}

double ObjectDimensions::getMinY()
{
	return yMin;
}

double ObjectDimensions::getMaxX()
{
	return xMax;
}

double ObjectDimensions::getMaxY()
{
	return yMax;
}

double ObjectDimensions::getImgWidth()
{
	return imgWidth;
}

double ObjectDimensions::getImgHeight()
{
	return imgHeight;
}

Direction ObjectDimensions::getCurrentDirection()
{
	return currentDirection;
}

void ObjectDimensions::setMinX(double userGivenMinX)
{
	xMin = userGivenMinX;
}

void ObjectDimensions::setMinY(double userGivenMinY)
{
	yMin = userGivenMinY;
}

void ObjectDimensions::setMaxX(double userGivenMaxX)
{
	xMax = userGivenMaxX;
}

void ObjectDimensions::setMaxY(double userGivenMaxY)
{
	yMax = userGivenMaxY;
}

void ObjectDimensions::setImgWidth(double userGivenImgWidth)
{
	imgWidth = userGivenImgWidth;
}

void ObjectDimensions::setImgHeight(double userGivenImgHeight)
{
	imgHeight = userGivenImgHeight;
}

void ObjectDimensions::setDirection(Direction userGivenDirection)
{
	currentDirection = userGivenDirection;
}

void ObjectDimensions::updateValues()
{
	
	xMax = xMin + imgWidth;
	yMax = yMin + imgHeight;
}
