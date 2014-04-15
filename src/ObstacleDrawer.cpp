#include "ObstacleDrawer.h"
#include "BlockPlatform.h"
#include "BusObject.h"
#include "HalfInvisibleBlock.h"
#include "ScrollerHole.h"
#include "SmallBlock.h"
#include "Spike.h"

ObstacleDrawer::ObstacleDrawer()
{
	obstacleInfo.clear();
	isCollidingWithObject = false;
	isCollidingWithEdge = false;
	isCollidingOnPlatformTop = false;
}

ObstacleDrawer::~ObstacleDrawer()
{
}

void ObstacleDrawer::loadObstacles()
{
	obstacleInfo.push_back(new BusObject());
	obstacleInfo.push_back(new BlockPlatform());
	obstacleInfo.push_back(new SmallBlock());
	obstacleInfo.push_back(new HalfInvisibleBlock());
	obstacleInfo.push_back(new Spike());
}

void ObstacleDrawer::unloadObstacles()
{
	for (int i = 0; i < obstacleInfo.size(); ++i)
		obstacleInfo[i]->unloadScrollerObstacle();
}

void ObstacleDrawer::testForCollision(Player* player, bool& isPlayerDead)
{
	for (int i = 0; i < obstacleInfo.size(); ++i)
		testForCollisionHelperFunction(player, obstacleInfo[i], isPlayerDead);
}

void ObstacleDrawer::testForCollisionHelperFunction(Player* player, ScrollerObstacle* obstacle, bool &isPlayerDead)
{
	isCollidingWithObject = cd.checkForCollision(player->getCurrentDimensions(), obstacle->getCurrentDimensions());
	isCollidingWithEdge = cd.checkForPlayerAtEdgeOfScreen(player->getCurrentDimensions());
	
	if (isCollidingWithObject)
		if (obstacle->getIsDeadly())
			isPlayerDead = true;
		else
			isCollidingOnPlatformTop = cd.isOnTopPlatform(player->getCurrentDimensions(), obstacle->getCurrentDimensions());
	else
		isCollidingOnPlatformTop = false;
		
	player->setIsOnPlatform(isCollidingOnPlatformTop);
	
	if (isCollidingWithObject && isCollidingWithEdge)
		isPlayerDead = true;
	else if (isCollidingWithObject)
		cd.fixCollision(player->getCurrentDimensions(), obstacle->getCurrentDimensions());
	else if (isCollidingWithEdge)
		cd.fixCollisionAtEdgeOfScreen(player->getCurrentDimensions());
}
