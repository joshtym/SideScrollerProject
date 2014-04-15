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
		///Gamescreen constructor
		/**Gamescreen sets up the Playable window that runs the main game logic from the timer function.
		 * It initializes the Player, the spikes.
		*/
		GameScreen();
		///Gamescreen destructor
		/**deletes 3 pointers for memory managment. User, platform and font.
		*/
		~GameScreen();
		
		///load Content sets the font and loads extranious data.
		/**
		 * load Content sets the font and loads extranious data.
		*/
		void loadContent();
		
		///Unloads the content and destroys obsticals
		/**
		 * Unload takes objects out and destroys objects like the destructor for images
		*/
		void unloadContent();
		
		///Update Content triggers Player and stage functions for game play.
		/**
		 * Updates player to trigger player position and draw functions. Also loops the background images
		 * so we can make the background look smooth and loop.
		*/
		void updateContent(ALLEGRO_EVENT ev);
		
		///triggers all draw functions
		/**
		 * triggers all draw functions
		*/
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
