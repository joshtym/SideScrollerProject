#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "GameScreenInterface.h"
#include <iostream>

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
	private:
		ScreenManager();
		ScreenManager(const ScreenManager&);
		ScreenManager& operator=(const ScreenManager&);
		
		//GameScreen *currentScreen, *newScreen;
	
	public:
		~ScreenManager();
		static ScreenManager &GetInstance();
		void Initialize();
		void addScreen(GameScreenInterface *screen);
		void loadContent();
		void update(ALLEGRO_EVENT ev);
		void draw(ALLEGRO_DISPLAY *display);
};
#endif
