#include "ObstacleDrawer.h"
#include "BlockPlatform.h"
#include "BusObject.h"
#include "HalfInvisibleBlock.h"
#include "ScrollerHole.h"
#include "SmallBlock.h"
#include "Spike.h"
#include <iostream>

ObstacleDrawer::ObstacleDrawer()
{
	obstacleInfo.clear();
	isCollidingWithObject = false;
	isCollidingWithEdge = false;
	isCollidingOnPlatformTop = false;
	allowNewDrawing = true;
	objectTimeOut = 0;
	maxX = 0;
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
	
	for (int i = 0; i < obstacleInfo.size(); i++)
		obstacleInfo[i]->loadScrollerObstacle();
		
}

void ObstacleDrawer::unloadObstacles()
{
	for (int i = 0; i < obstacleInfo.size(); i++)
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

void ObstacleDrawer::drawObstacles(double obstacleIncrementalValue)
{
	int randomValue = rand() % 100;
	int randomValue2;
	maxX = 0;
	
	for (int i = 0; i < obstacleInfo.size(); i++)
	{
		if (obstacleInfo[i]->getIsBeingDrawn())
		{
			obstacleInfo[i]->draw(obstacleIncrementalValue);
			obstacleInfo[i]->getCurrentDimensions().updateValues();
			std::cout << obstacleInfo[i]->getCurrentDimensions().getMaxX() << std::endl;
			tempMaxX = obstacleInfo[i]->getCurrentDimensions().getMaxX();
			
			if (tempMaxX > maxX)
				maxX = tempMaxX;
		}
	}
	
	if (maxX < 800)
		allowNewDrawing = true;
	else
		allowNewDrawing = false;
		
	randomValue2 = rand() % obstacleInfo.size();
	
	while (obstacleInfo[randomValue2]->getIsBeingDrawn())
		randomValue2 = rand() % obstacleInfo.size();
	
	if (allowNewDrawing && randomValue == 0)
	{
		allowNewDrawing = false;
		obstacleInfo[randomValue2]->draw(obstacleIncrementalValue);
	}
}
