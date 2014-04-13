#include "TdObject.h"
#include <iostream>

 
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

int TdObject::getMinX()
{
	return xMin;
}

int TdObject::getMaxX()
{
	return xMax;
}

int TdObject::getMinY()
{
	return yMin;
}

int TdObject::getMaxY()
{
	return yMax;
}

void TdObject::calcMixMax()
{
	xMin = x;
	xMax = xMin + xWidth;
	
	yMin = y;
	yMax = yMin + yHeight;
}


bool TdObject::isColliding(TdObject *iTdo)
{
	calcMixMax();
	//std::cout << "MinY of Player: " << yMin << std::endl;
	if(!(xMax < iTdo->getMinX() || xMin > iTdo->getMaxX() ))
	{
		//std::cout << "MaxY of Platform: " << iTdo->getMaxY() << std::endl;
		if(!(yMax < iTdo->getMinY() || yMin > iTdo->getMaxY()))
		{
			return true;
		}
	}
	return false;
}






