#include "ScreenManager.h"
#include "InputManagement.h"
#include "Display.h"
#include <vector>

int main()
{
	const double FPS = 60;
	
	int screenWidth, screenHeight;
	std::vector<int> keys;
	ALLEGRO_KEYBOARD_STATE keyState;
	bool completed;
	InputManagement input;
	
	completed = false;
	screenWidth = 800;
	screenHeight = 600;
	Display d(screenWidth, screenHeight);
	ALLEGRO_TIMER *timer = al_create_timer (1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(d.getAllegroDisplay()));
	
	keys.push_back(ALLEGRO_KEY_ESCAPE);
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().loadContent();
	
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
		
		ScreenManager::GetInstance().update(ev);
		ScreenManager::GetInstance().draw(d.getAllegroDisplay());
		
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	
	ScreenManager::GetInstance().unloadContent();
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	
	return 0;
}
