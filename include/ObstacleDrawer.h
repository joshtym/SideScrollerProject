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
		
	private:
		void testForCollisionHelperFunction(Player*, ScrollerObstacle*, bool&);
		std::vector<ScrollerObstacle*> obstacleInfo;
		CollisionDetection cd;
		bool isCollidingWithObject;
		bool isCollidingWithEdge;
		bool isCollidingOnPlatformTop;
};
#endif
