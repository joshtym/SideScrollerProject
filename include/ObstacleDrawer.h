#ifndef OBSTACLEDRAWER_H
#define OBSTACLEDRAWER_H

#include <vector>
#include <allegro5/allegro.h>
#include "ScrollerObstacle.h"
#include "ObjectDimensions.h"
#include "CollisionDetection.h"
#include "Player.h"

class ObstacleDrawer
{
	public:
		ObstacleDrawer();
		~ObstacleDrawer();
		void loadObstacles();
		void unloadObstacles();
		void testForCollision(Player*, bool&);
		void drawObstacles(double);
		
	private:
		void testForCollisionHelperFunction(Player*, ScrollerObstacle*, bool&);
		std::vector<ScrollerObstacle*> obstacleInfo;
		std::vector<ScrollerObstacle*> possibleNewObjectsToBeDrawn;
		CollisionDetection cd;
		bool isCollidingWithObject;
		bool isCollidingWithEdge;
		bool isCollidingOnPlatformTop;
		bool allowNewDrawing;
		int objectTimeOut;
		int tempMaxX;
		int maxX;
};
#endif
