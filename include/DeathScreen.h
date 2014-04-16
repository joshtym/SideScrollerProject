#ifndef DEATHSCREEN_H
#define DEATHSCREEN_H

#include "ScreenManager.h"
#include <iostream>
#include <sstream>

/// Class: DeathScreen
/**
 * Purpose: A screen which is displayed after the character dies 
 * showing the score for that game this allows the user to press 
 * enter to try the game again
 *          
**/
class DeathScreen : public GameScreenInterface
{
	public:
		/// Constructor: DeathScreen
		/**
		 * Purpose: Constructs a DeathScreen which takes in the  
		 * current score for later display 
		 * allows the user to press enter to try the game again
		**/
		DeathScreen(int);

		/// Destructor: DeathScreen
		/**
		 * Purpose: Destructs a DeathScreen which cleans up all   
		 * the asset files and any memory 
		**/
		~DeathScreen();
		
		/// Load Content
		/**
		 * Purpose: Loads assets for later display   
		 * the asset files and any memory 
		**/
		void loadContent();

		/// UnLoad Content
		/**
		 * Purpose: UnLoads assets for memory freeing   
		**/
		void unloadContent();

		/// Update Content
		/**
		 * Purpose: UnLoads assets for memory freeing   
		**/
		void updateContent(ALLEGRO_EVENT ev);

		/// Draw Content
		/**
		 * Purpose: Draws the background as well as the score from gamescreen   
		**/
		void draw(ALLEGRO_DISPLAY *display);
		
	private:
		
		ALLEGRO_FONT *font;
		ALLEGRO_BITMAP *bitmap;
		std::ostringstream oss;
		int Finalscore;
};
#endif
