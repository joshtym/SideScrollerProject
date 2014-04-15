#ifndef DEATHSCREEN_H
#define DEATHSCREEN_H

#include "ScreenManager.h"

class DeathScreen : public GameScreenInterface
{
	public:
		DeathScreen();
		~DeathScreen();
		
		void loadContent();
		void unloadContent();
		void updateContent(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY *display);
		
	private:
		ALLEGRO_FONT *font;
		ALLEGRO_BITMAP *bitmap;
};
#endif
