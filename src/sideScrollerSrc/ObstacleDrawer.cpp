#include "ObstacleDrawer.h"
#include "BlockPlatform.h"
#include "BusObject.h"
#include "HalfInvisibleBlock.h"
#include "ScrollerHole.h"
#include "SmallBlock.h"
#include "Spike.h"
#include "FireHydrant.cpp"

ObstacleDrawer::ObstacleDrawer()
{
	// Ensure the initialized vector is cleared
	obstacleInfo.clear();
	
	// Assign defaults
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
	// Push back all the possible blocks
	obstacleInfo.push_back(new BusObject());
	obstacleInfo.push_back(new BlockPlatform());
	obstacleInfo.push_back(new SmallBlock());
	obstacleInfo.push_back(new HalfInvisibleBlock());
	obstacleInfo.push_back(new Spike());
	obstacleInfo.push_back(new FireHydrant());
	
	// Load each subsequent block
	for (int i = 0; i < obstacleInfo.size(); i++)
		obstacleInfo[i]->loadScrollerObstacle();
}

void ObstacleDrawer::unloadObstacles()
{
	// Unload each block in the vector
	for (int i = 0; i < obstacleInfo.size(); i++)
		obstacleInfo[i]->unloadScrollerObstacle();
}

void ObstacleDrawer::testForCollision(Player* player, bool& isPlayerDead)
{
	// Test for collision of each object. This object calls its helper
	// function to check each individual function
	for (int i = 0; i < obstacleInfo.size(); ++i)
		testForCollisionHelperFunction(player, obstacleInfo[i], isPlayerDead);
}

void ObstacleDrawer::testForCollisionHelperFunction(Player* player, ScrollerObstacle* obstacle, bool &isPlayerDead)
{
	// Determine if player is colliding with either the edge or the obstacle
	isCollidingWithObject = cd.checkForCollision(player->getCurrentDimensions(), obstacle->getCurrentDimensions());
	isCollidingWithEdge = cd.checkForPlayerAtEdgeOfScreen(player->getCurrentDimensions());
	
	// Determine whether player should die or collision is on a platform
	if (isCollidingWithObject)
	{
		if (obstacle->getIsDeadly())
			isPlayerDead = true;
		else if(cd.isOnTopPlatform(player->getCurrentDimensions(), obstacle->getCurrentDimensions()))
			player->setIsOnPlatform(true);
	}
	else
		isCollidingOnPlatformTop = false;
		
	
	// Of course if the player is between the edge and an object, they
	// will die, else fix the collision
	if (isCollidingWithObject && isCollidingWithEdge)
		isPlayerDead = true;
	else if (isCollidingWithObject)
		cd.fixCollision(player->getCurrentDimensions(), obstacle->getCurrentDimensions());
	else if (isCollidingWithEdge)
		cd.fixCollisionAtEdgeOfScreen(player->getCurrentDimensions());
}

void ObstacleDrawer::drawObstacles(double obstacleIncrementalValue)
{
	// Assign local variables
	int randomValue = rand() % 100;
	int randomValue2 = rand() % obstacleInfo.size();
	maxX = 0;
	int numOfObjectsOnScreen = 0;
	
	// Essentially, this will prevent any objects that are being
	// drawn from overlapping and assigns the currently maxX value
	// of the block being drawn
	for (int i = 0; i < obstacleInfo.size(); i++)
	{
		if (obstacleInfo[i]->getIsBeingDrawn())
		{
			obstacleInfo[i]->draw(obstacleIncrementalValue);
			obstacleInfo[i]->getCurrentDimensions().updateValues();
			tempMaxX = obstacleInfo[i]->getCurrentDimensions().getMaxX();
			
			if (tempMaxX > maxX)
				maxX = tempMaxX;
				
			numOfObjectsOnScreen++;
		}
	}
	
	// If block is now fully on screen, allow another block to be drawn
	if (maxX < 800)
		allowNewDrawing = true;
	else
		allowNewDrawing = false;
	
	// When determining what our new object should be, we don't want
	// to draw something that's already drawn, so we get a new object
	// to be drawn
	while (obstacleInfo[randomValue2]->getIsBeingDrawn())
		randomValue2 = rand() % obstacleInfo.size();
	
	if (allowNewDrawing && randomValue == 0 && numOfObjectsOnScreen < 4)
	{
		allowNewDrawing = false;
		obstacleInfo[randomValue2]->draw(obstacleIncrementalValue);
	}
}
