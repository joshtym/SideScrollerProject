#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "GameScreenInterface.h"
#include "ScreenTransition.h"

// Allegro Inits
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class ScreenManager
{
	public:
		/// Destructor of the Screen Manager
		/**
		 * Deallocates any allocated memory
		**/
		~ScreenManager();
		
		/// Instance getter which allows for usage of the
		/// singleton class
		/**
		 * Allows for the concept of a singleton class, in which
		 * only one instance of this class is available. This allows 
		 * us to easily switch between screens
		**/
		static ScreenManager &GetInstance();
		
		/// Initialization of the Singleton Class
		/**
		 * Creates the first screen that starts on initialization
		**/
		void Initialize();
		
		/// Adds in a new Screen
		/**
		 * Creates a new screen and removes the old one. Makes
		 * the transition
		**/
		void addScreen(GameScreenInterface *screen);
		
		/// Loads correct resources for transition
		/**
		 * Loads up transition image and resources for current
		 * screen. Also actually starts the transition using
		 * the animation class
		**/
		void loadContent();
		
		/// Unloads allegro allocated resources from screen
		/**
		 * Destroys bitmaps, fonts, etc and unloads the screen
		**/
		void unloadContent();
		
		/// Update the content of the screen
		/**
		 * If we're not currently in a transition, this will
		 * call the update of the Screen function. If it is, it calls
		 * the helper transitionHandler function to do the transition
		**/
		void update(ALLEGRO_EVENT ev);
		
		/// Draw the appropiate images on the screen
		/**
		 * Calls the subfunctions to draw the correct images to the
		 * screen
		**/
		void draw(ALLEGRO_DISPLAY *display);
		
	private:
		/// Private Constructors
		/**
		 * Since this is a singleton class, we don't want people
		 * to be able to create more than one instance of the
		 * ScreenManager class
		**/
		ScreenManager();
		ScreenManager(const ScreenManager&);
		ScreenManager& operator=(const ScreenManager&);
		
		/// Declared private variables for the screenManager class
		ALLEGRO_BITMAP* transitionImage;
		Animation transition;
		ScreenTransition screenT;
		GameScreenInterface *currentScreen, *newScreen;
		bool startOfTransition;
		
		/// Helper function to deal with the transition
		void transitionHandler();
};
#endif
