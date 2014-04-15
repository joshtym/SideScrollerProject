#ifndef SCROLLEROBSTACLE_H
#define SCROLLEROBSTACLE_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include "ObjectDimensions.h"

class ScrollerObstacle
{
	public:
		virtual void loadScrollerObstacle() = 0;
		virtual void unloadScrollerObstacle();
		virtual void update(double);
		virtual void draw();
		virtual ObjectDimensions& getCurrentDimensions();
		bool getIsDeadly();
		
	protected:
		ALLEGRO_BITMAP *scrollerObstacleBitmap;
		ObjectDimensions scrollerObstacleDimension;
		bool isTransparent;
		bool isDeadly=false;
};
#endif
 
