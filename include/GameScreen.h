#ifndef GAMESCREEN_H
#define GAMESCREE_H

#include "GameScreenInterface.h"
#include "Player.h"
#include "Platform.h"
#include "CollisionDetection.h"

class GameScreen : public GameScreenInterface
{
	public:
		GameScreen();
		~GameScreen();
		
		void loadContent();
		void unloadContent();
		void updateContent(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY*);
		
	private:
		Player *userPlayer;
		Platform *userPlatform;
		ALLEGRO_BITMAP *bitmap;
		CollisionDetection cd;
		int time;
		int imageXValue;
		int platformXValue;
};
#endif
