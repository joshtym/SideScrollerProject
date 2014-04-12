#ifndef PLATFORM_H
#define PLATFORM_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include "ObjectDimensions.h"

class Platform 
{
	public:
		virtual void loadPlatform() = 0;
		virtual void unloadPlatform();
		virtual void update(double);
		virtual void draw();
		virtual ObjectDimensions& getCurrentDimensions();
		
	protected:
		ALLEGRO_BITMAP *platformBitmap;
		ALLEGRO_BITMAP *platformBitmap2;
		ObjectDimensions platformDimension;
};
#endif
 
