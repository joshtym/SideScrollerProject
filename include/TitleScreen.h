#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "ScreenManager.h"
#include "InputManager.h"

class TitleScreen : public GameScreenInterface
{
	private:
		ALLEGRO_FONT *font;
	public:
		TitleScreen();
		~TitleScreen();
		void loadContent();
		void unloadContent();
		void update(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY *display);
};
#endif
