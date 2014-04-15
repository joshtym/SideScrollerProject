#ifndef DEATHSCREEN_H
#define DEATHSCREEN_H

#include "ScreenManager.h"
#include <iostream>
#include <sstream>
using namespace std;

class DeathScreen : public GameScreenInterface
{
	public:
		DeathScreen(int);
		~DeathScreen();
		
		void loadContent();
		void unloadContent();
		void updateContent(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY *display);
		
	private:
		ALLEGRO_FONT *font;
		ALLEGRO_BITMAP *bitmap;
		ostringstream oss;
		int Finalscore;
};
#endif
