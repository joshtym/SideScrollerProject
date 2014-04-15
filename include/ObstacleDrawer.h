#ifndef OBSTACLEDRAWER_H
#define OBSTACLEDRAWER_H

#include <vector>
#include <allegro5/allegro.h>
#include "ScrollerObstacle.h"

class ObstacleDrawer
{
	public:
		ObstacleDrawer();
		~ObstacleDrawer();
		void loadObstacles();
		void unloadObstacles();
		
	private:
		std::vector<ScrollerObstacle*> obstacleInfo;
};
#endif
