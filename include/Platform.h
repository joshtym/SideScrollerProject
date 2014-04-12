#ifndef PLATFORM_H
#define PLATFORM_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>

class Platform 
{
	private:
		ALLEGRO_BITMAP *platformBitmap;
		
		int floor = 300;
		void setX(int);
		void setY(int);
		
		
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
		
		
};
#endif
 
