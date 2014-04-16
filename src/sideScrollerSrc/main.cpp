#include <vector>
#include <ctime>
#include <cstdlib>
#include "ScreenManager.h"
#include "InputManagement.h"
#include "Display.h"

int main()
{
	// Make sure randomization works
	srand(time(0));
		
	// Assign const fps variable
	const double FPS = 60;
	
	// Variable declarations
	int screenWidth, screenHeight;
	bool completed;
	std::vector<int> keys;
	ALLEGRO_KEYBOARD_STATE keyState;
	InputManagement input;
	
	// Assign default values
	completed = false;
	screenWidth = 800;
	screenHeight = 600;
	
	// Create display, timer and event queue
	Display d(screenWidth, screenHeight);
	ALLEGRO_TIMER *timer = al_create_timer (1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	
	// Register all the event sources
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(d.getAllegroDisplay()));
	
	keys.push_back(ALLEGRO_KEY_ESCAPE);
	
	// Initialize the intance of screen manager
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().loadContent();
	
	// Start timer and jump into the while loop
	al_start_timer(timer);
	
	while (!completed)
	{
		// Wait for and get keyboard event
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		al_get_keyboard_state(&keyState);
		
		// Checks if any of the keys are pressed that will close the
		// program. In this case, that key equates to ESC
		if (input.isKeyReleased(ev, keys))
			completed = true;
		
		// If the x button is hit, close the display
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			completed = true;
		
		// Update the screen/draw to the buffer not being displayed
		ScreenManager::GetInstance().update(ev);
		ScreenManager::GetInstance().draw(d.getAllegroDisplay());
		
		// Flip buffers
		al_flip_display();
		
		// Clear the now not being used buffer
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	
	// Unload all content from screen manager
	ScreenManager::GetInstance().unloadContent();
	
	// Destroy allegro stuff
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	
	return 0;
}
