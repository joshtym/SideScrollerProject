#ifndef GAMESCREEN_H
#define GAMESCREE_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <sstream>
#include "GameScreenInterface.h"
#include "Player.h"
#include "ObstacleDrawer.h"

using namespace std;

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
		ObstacleDrawer obstacles;
		ALLEGRO_BITMAP *bitmap;
		ALLEGRO_BITMAP *bitmap1;
		int time;
		int imageXValue;
		int platformXValue;
		bool isPlayerDead;
		ALLEGRO_FONT *font;
		ostringstream oss;
		int score;
		double timeIncrementaleValue;
		double maxSpeed;
		double speed = 0;
		bool isNight;
};
#endif
