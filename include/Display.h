#ifndef DISPLAY_H
#define DISPLAY_H

#include "ScreenManager.h"

class Display
{
	public:
		Display();
		Display(int, int);
		~Display();
		ALLEGRO_DISPLAY *getAllegroDisplay() const { return display;}
		int getWidth() const;
		int getHeight() const;
	
	private:
		ALLEGRO_DISPLAY *display;
		int width;
		int height;
		void initialize();
};
#endif
