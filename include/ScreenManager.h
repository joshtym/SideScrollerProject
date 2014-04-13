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
		~ScreenManager();
		static ScreenManager &GetInstance();
		void Initialize();
		void addScreen(GameScreenInterface *screen);
		void loadContent();
		void unloadContent();
		void update(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY *display);
		
	private:
		ScreenManager();
		ScreenManager(const ScreenManager&);
		ScreenManager& operator=(const ScreenManager&);
		ALLEGRO_BITMAP* transitionImage;
		Animation transition;
		ScreenTransition screenT;
		GameScreenInterface *currentScreen, *newScreen;
		void transitionHandler();
		bool startOfTransition;
};
#endif
