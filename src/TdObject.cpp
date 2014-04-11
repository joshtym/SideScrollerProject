#include "TdObject.h"

 
TdObject::TdObject()
{
	
	
}

int TdObject::getX()
{
	return x;
}
int TdObject::getY()
{
	return y;
}
int TdObject::getYHeight()
{
	return yHeight;
}
int TdObject::getXWidth()
{
	return xWidth;
}

int TdObject::setX(int set)
{
	x = set;
}
int TdObject::setY(int set)
{
	y = set;
}
int TdObject::setYHeight(int set)
{
	yHeight = set;
}
int TdObject::setXWidth(int set)
{
	xWidth = set;
}
