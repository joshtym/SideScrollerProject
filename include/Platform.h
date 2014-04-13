#ifndef PLATFORM_H
#define PLATFORM_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include "ObjectDimensions.h"

class Platform 
{
	private:
		ALLEGRO_BITMAP *platformBitmap;
		ObjectDimensions platformDimension;
		
	public:
		Platform();
		~Platform();
		void loadPlatform();
		void unloadPlatform();
		void update(double, double);
		void draw();
		ObjectDimensions getCurrentDimensions();
};
#endif
 
