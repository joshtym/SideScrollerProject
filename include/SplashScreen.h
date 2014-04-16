#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "ScreenManager.h"

/// SplashScreen class inherited from GameScreenInterface
/**
 * SplashScreen class which is the first image shown upon initial
 * load up. Leads into titleScreen
**/
class SplashScreen : public GameScreenInterface
{
	public:
		/// Constructor for Splash Screen
		SplashScreen();
		
		/// Destructor for Splash Screen
		~SplashScreen();
		
		/// Function to load the content
		/**
		 * Function to load the bitmap for the splash screen
		**/
		void loadContent();
		
		/// Function to unload the content
		/**
		 * Function to destroy the bitmap for the splash screen
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
		ALLEGRO_FONT *font;
		ALLEGRO_BITMAP *bitmap;
};
#endif
