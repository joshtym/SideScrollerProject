#ifndef GAMESCREEN_H
#define GAMESCREE_H

#include "GameScreenInterface.h"
#include "Player.h"
#include "CollisionDetection.h"

class GameScreen : public GameScreenInterface
{
	private:
		Player *userPlayer;
		ALLEGRO_BITMAP *bitmap;
		CollisionDetection cd;
		
	public:
		GameScreen();
		~GameScreen();
		
		void loadContent();
		void unloadContent();
		void updateContent(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY*);
		
};
#endif
