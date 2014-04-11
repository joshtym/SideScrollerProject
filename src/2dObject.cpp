#include "2dObject.h"

 
2dObject::2dObject()
{
	
	
}

int 2dObject::getX()
{
	return x;
}
int 2dObject::getY()
{
	return y;
}
int 2dObject::getYHeight()
{
	return getYHeight;
}
int 2dObject::getXWidth()
{
	return xWidth;
}

int 2dObject::setX(int set)
{
	x = set;
}
int 2dObject::setY(int set)
{
	y = set;
}
int 2dObject::setYHeight(int set)
{
	yHeight = set;
}
int 2dObject::setXWidth(int set)
{
	xWidth = set;
}
