#include "ObstacleDrawer.h"
#include "BlockPlatform.h"
#include "BusObject.h"
#include "HalfInvisibleBlock.h"
#include "ScrollerHole.h"
#include "SmallBlock.h"

ObstacleDrawer::ObstacleDrawer()
{
	obstacleInfo.clear();
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
	obstacleInfo.push_back(new ScrollerHole());
}

void ObstacleDrawer::unloadObstacles()
{
	for (int i = 0; i < obstacleInfo.size(); ++i)
		obstacleInfo[i]->unloadScrollerObstacle();
}
