#ifndef PLATFORM_H
#define PLATFORM_H

#include "TdObject.h"
#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>

class Platform 
{
	private:
		ALLEGRO_BITMAP *platformBitmap;
		TdObject *tdo;
		int floor = 300;
		
		//x and y are image
		int imgWidth;
		int imgHeight;
		int x;
		int y;
		int xWidth;
		int yHeight;
		
	public:
		Platform();
		~Platform();
		void loadPlatform();
		void unloadPlatform();
		void draw();
		int getX();
		int getY();
		void setX(int);
		void setY(int);
		TdObject* getTdo();
		
		
};
#endif
 
