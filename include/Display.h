#ifndef DISPLAY_H
#define DISPLAY_H

// Allegro Inits
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

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
