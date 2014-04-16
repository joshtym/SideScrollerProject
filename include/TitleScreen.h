#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "ScreenManager.h"

/// TitleScreen class inherited from GameScreenInterface
/**
 * TitleScreen class which is the first image shown after initial
 * load up. Leads into GameScreen
**/
class TitleScreen : public GameScreenInterface
{	
	public:
		/// Constructor for TitleScreen
		TitleScreen();
		
		/// Destructor for TitleScreen
		~TitleScreen();
		
		/// Function to load the content
		/**
		 * Function to load the bitmap for the title screen
		**/
		void loadContent();
		
		/// Function to unload the content
		/**
		 * Function to destroy the bitmap for the title screen
		**/
		void unloadContent();
		
		/// Function to update all the content of the screen
		/**
		 * Checks to see what the user is inputing with the keyboard
		 * If the input is the enter key, it "updates" the screen and
		 * moves on to the Title screen, else, does nothing
		**/
		void updateContent(ALLEGRO_EVENT ev);
		
		/// Function that draws the display
		/**
		 * Draws the loaded bitmap to the screen
		**/
		void draw(ALLEGRO_DISPLAY *display);
		
	private:
		ALLEGRO_BITMAP *bitmap;
};
#endif
