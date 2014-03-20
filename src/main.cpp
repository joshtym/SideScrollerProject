#include "ScreenManager.h"
#include "InputManagement.h"
#include "Display.h"
#include "TitleScreen.h"
#include "SplashScreen.h"
#include <iostream>
#include <vector>

#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main()
{
	int screenWidth, screenHeight;
	screenWidth = 800;
	screenHeight = 600;
	const double FPS = 60;
	Display d(800, 600);
	
	ALLEGRO_TIMER *timer = al_create_timer (1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_KEYBOARD_STATE keyState;
	
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(d.getAllegroDisplay()));
	
	bool completed = false;
	
	InputManagement input;
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().loadContent();
	
	std::vector<int> keys;
	
	keys.push_back(ALLEGRO_KEY_DOWN);
	keys.push_back(ALLEGRO_KEY_ESCAPE);
	
	al_start_timer(timer);
	
	while (!completed)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		al_get_keyboard_state(&keyState);
		
		if (input.isKeyReleased(ev, keys))
			completed = true;
		
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			completed = true;
			
		if (input.isKeyPressed(ev, ALLEGRO_KEY_E))
			ScreenManager::GetInstance().addScreen(new TitleScreen());
		
		if (input.isKeyPressed(ev, ALLEGRO_KEY_R))
			ScreenManager::GetInstance().addScreen(new SplashScreen());
		//ScreenManager::GetInstance().update(ev);
		ScreenManager::GetInstance().draw(d.getAllegroDisplay());
		
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	
	//al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	
	return 0;
}
