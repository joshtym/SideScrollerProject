#ifndef GAMESCREENINTERFACE_H
#define GAMESCREENINTERFACE_H

#include "InputManagement.h"

/// Class that defines an Interface for all Game Screens
/**
 * Using a few virtual functions, this is the base class for all
 * game screen related creations
**/
class GameScreenInterface
{		
	public:
		GameScreenInterface();
		~GameScreenInterface();
		
		/// Function that will load the content of the screen.
		/**
		 * Things such as bitmaps, fonts, and player pngs are loaded
		 * in this functionj
		**/
		virtual void loadContent();
		
		/// Virtual function to unload content of the screen
		/**
		 * Unload the content of the current screen
		**/
		virtual void unloadContent();
		
		/// Virtual function to update all the content on the screen
		/**
		 * Update the current content dependant on the allegro event
		**/
		virtual void updateContent(ALLEGRO_EVENT ev);
		
		/// Virtual function to draw the screen
		/**
		 * Draw the updated content
		**/
		virtual void draw(ALLEGRO_DISPLAY*);
		
		InputManagement getInput();
		
	protected:
		InputManagement input;
};
#endif
