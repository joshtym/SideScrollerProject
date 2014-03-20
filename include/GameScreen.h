#ifndef GAMESCREEN_H
#define GAMESCREE_H

#include "GameScreenInterface.h"

class GameScreen : public GameScreenInterface
{
	public:
		GameScreen();
		~GameScreen();
		
		void loadContent();
		void unloadContent();
		void updateContent(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY*);
};
#endif
