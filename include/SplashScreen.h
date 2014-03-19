#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "ScreenManager.h"

class SplashScreen : public GameScreenInterface
{
	private:
		ALLEGRO_FONT *font;
	public:
		SplashScreen();
		~SplashScreen();
		
		void loadContent();
		void unloadContent();
		void update(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY *display);
};
#endif
