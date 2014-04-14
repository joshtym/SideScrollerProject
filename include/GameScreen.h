#ifndef GAMESCREEN_H
#define GAMESCREE_H

#include "GameScreenInterface.h"
#include "Player.h"
#include "ScrollerObstacle.h"
#include "CollisionDetection.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <sstream>

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
		ScrollerObstacle *userPlatform;
		ALLEGRO_BITMAP *bitmap;
		CollisionDetection cd;
		int time;
		int imageXValue;
		int platformXValue;
		bool playerIsDead;
		bool isCollidingWithObject;
		bool isCollidingWithEdge;
		bool isCollidingOnPlatformTop;
		ALLEGRO_FONT *font;
		ostringstream oss;
		int score;
		double timeIncrementaleValue;
		double maxSpeed;
		double speed = 0;
};
#endif
