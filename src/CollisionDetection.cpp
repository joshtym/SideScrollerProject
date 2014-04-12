#include "CollisionDetection.h"



CollisionDetection::CollisionDetection()
{
	
}

CollisionDetection::~CollisionDetection()
{
	
}

void CollisionDetection::calculateFloor()
{
	int yPos = p->getY();
	
	//check yPos against list of platforms yPos get x value
	
	//p->setFloor(300);
}

void CollisionDetection::setPlayer(Player* player)
{
	p = player;
}
