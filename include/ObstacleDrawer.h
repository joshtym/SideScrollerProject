#ifndef OBSTACLEDRAWER_H
#define OBSTACLEDRAWER_H

#include <vector>

class ObstacleDrawer
{
	public:
		ObstacleDrawer();
		~ObstacleDrawer();
		
	private:
		vector<ALLEGRO_BITMAP*> obstacles;
};
#endif
