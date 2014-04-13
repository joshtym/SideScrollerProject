#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "ScreenManager.h"

class SplashScreen : public GameScreenInterface
{
	public:
		SplashScreen();
		~SplashScreen();
		
		void loadContent();
		void unloadContent();
		void updateContent(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY *display);
		
	private:
		ALLEGRO_FONT *font;
		ALLEGRO_BITMAP *bitmap;
};
#endif
