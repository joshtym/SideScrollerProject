#include "ScreenManager.h"
#include "InputManager.h"
#include <iostream>
#include <vector>

int main()
{
	ALLEGRO_DISPLAY *display;
	
	int screenWidth, screenHeight;
	screenWidth = 800;
	screenHeight = 600;
	const double FPS = 60;
	
	if (!al_init())
	{
		al_show_native_message_box(0, "Error", "Error",
		"Cannot Initialize Allegro", 0, 0);
		return -1;
	}
	
	display = al_create_display(screenWidth, screenHeight);
	
	if (!display)
	{
		al_show_native_message_box(0, "Error", "Error",
		"Cannot create display", 0, 0);
		
		return -1;
	}
	
	al_set_window_position(display, 100, 100);
	
	al_install_keyboard();
	al_install_mouse();
	
	al_init_image_addon();
	al_init_acodec_addon();
	
	al_init_font_addon();
	al_init_ttf_addon();
	
	ALLEGRO_TIMER *timer = al_create_timer (1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_KEYBOARD_STATE keyState;
	
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	
	bool completed = false;
	
	InputManager input;
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().loadContent();
	
	std::vector<int> keys;
	
	keys.push_back(ALLEGRO_KEY_DOWN);
	keys.push_back(ALLEGRO_KEY_ESCAPE);
	
	al_start_timer(timer);
	
	while (!completed)
	{
		std::cout << "1!" << std::endl;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		al_get_keyboard_state(&keyState);
		
		std::cout << "2!" << std::endl;
		if (input.isKeyReleased(ev, keys))
			completed = true;
		
		std::cout << "3!" << std::endl;
		ScreenManager::GetInstance().update(ev);
		ScreenManager::GetInstance().draw(display);
		
		std::cout << "4!" << std::endl;
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		std::cout << "5!" << std::endl;
	}
	
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	
	return 0;
}
