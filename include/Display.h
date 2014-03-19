#ifndef DISPLAY_H
#define DISPLAY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

class Display
{
	public:
		Display();
		Display(int, int);
		~Display();
	
	private:
		ALLEGRO_DISPLAY *display;
		int width;
		int height;
};
#endif
