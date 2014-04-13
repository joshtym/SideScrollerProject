#include "CollisionDetection.h"

CollisionDetection::CollisionDetection()
{
	
}

CollisionDetection::~CollisionDetection()
{
	
}

void CollisionDetection::calculateFloor()
{
	//int yPos = p->getY();
	//check yPos against list of platforms yPos get x value
	
	//p->setFloor(300);
}

void CollisionDetection::setPlayer(Player* player)
{
	//p = player;
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
}*/
