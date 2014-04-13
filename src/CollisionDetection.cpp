#include "CollisionDetection.h"

CollisionDetection::CollisionDetection()
{
	
}

CollisionDetection::~CollisionDetection()
{
}

bool CollisionDetection::checkForCollision(ObjectDimensions player, ObjectDimensions obj)
{
	if(!(player.getMaxX() < obj.getMinX() || player.getMinX() > obj.getMaxX()))
		if(!(player.getMaxY() < obj.getMinY() || player.getMinY() > obj.getMaxY()))
			return true;
					
	return false;
}

void CollisionDetection::CollisionDetection::fixCollision(ObjectDimensions& player, ObjectDimensions& obj)
{
	fixCollisionLeftSide(player, obj);
	fixCollisionRightSide(player, obj);
	fixCollisionTopPlatform(player, obj);
	fixCollisionBottomPlatform(player, obj);
					
}

void CollisionDetection::fixCollisionLeftSide(ObjectDimensions& player, ObjectDimensions& obj)
{
	if (player.getMaxX() >= obj.getMinX())
		if ((player.getMaxX() - obj.getMinX()) < (obj.getMaxX() - player.getMinX()))
			if ((player.getMaxX() - obj.getMinX()) < (obj.getMaxY() - player.getMinY()))
				if ((player.getMaxX() - obj.getMinX()) < (player.getMaxY() - obj.getMinY()))
					player.setMinX(player.getMinX() - (player.getMaxX() - obj.getMinX()));
}

void CollisionDetection::fixCollisionRightSide(ObjectDimensions& player, ObjectDimensions& obj)
{				
	if (player.getMinX() <= obj.getMaxX())
		if ((obj.getMaxX() - player.getMinX()) < (player.getMaxX() - obj.getMinX()))
			if ((obj.getMaxX() - player.getMinX()) < (obj.getMaxY() - player.getMinY()))
				if ((obj.getMaxX() - player.getMinX()) < (player.getMaxY() - player.getMinY()))
					player.setMinX(player.getMinX() + (obj.getMaxX() - player.getMinX()));
}

void CollisionDetection::fixCollisionTopPlatform(ObjectDimensions& player, ObjectDimensions& obj)
{
	if (player.getMaxY() >= obj.getMinY())
		if ((player.getMaxY() - obj.getMinY()) < (player.getMaxX() - obj.getMinX()))
			if ((player.getMaxY() - obj.getMinY()) < (obj.getMaxX() - player.getMinX()))
				if ((player.getMaxY() - obj.getMinY()) < (obj.getMaxY() - player.getMinY()))
					player.setMinY(player.getMinY() - (player.getMaxY() - obj.getMinY()));
}

void CollisionDetection::fixCollisionBottomPlatform(ObjectDimensions& player, ObjectDimensions& obj)
{
	if (player.getMinY() <= obj.getMaxY())
		if ((obj.getMaxY() - player.getMinY()) < (player.getMaxX() - obj.getMinX()))
			if ((obj.getMaxY() - player.getMinY()) < (obj.getMaxX() - player.getMinX()))
				if ((obj.getMaxY() - player.getMinY()) < (player.getMaxY() - obj.getMinY()))
					player.setMinY(player.getMinY() + (obj.getMaxY() - player.getMinY()));
}

/*bool CollisionDetection::isColliding(TdObject *iTdo)
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
	* 
	* 
	if (!(player.getMaxX() < obj.getMinX() || player.getMinX() > obj.getMaxX()))
	{
		if (player.getMaxY() < obj.getMinY() || player.getMinY() > obj.getMaxY())
			return 0;
		else if (player.getMaxY() >= obj.getMinY() && player.getMinY() < obj.getMinY())
			return 1;
		else if (player.getMinY() <= obj.getMaxY() && player.getMaxY() > obj.getMaxY())
			return 2;
	}
}*/
