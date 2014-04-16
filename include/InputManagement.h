#ifndef INPUTMANAGEMENT_H
#define INPUTMANAGEMENT_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <vector>

/// Class to deal with Input
/**
 * Class handles all interactions with user inputs
**/
class InputManagement
{
	public:
		/// Constructor for Input Management
		InputManagement();
		
		/// Destructor for Input Management
		~InputManagement();
		
		/// Function handles updating an input
		/**
		 * Essentially waits for a new keyState to occur.
		**/
		void update();
		
		/// Detects if a key is pressed
		/**
		 * Takes in either a single key or a vector of keys, and
		 * detects if that current key is being pressed in the allegro
		 * event
		**/
		bool isKeyPressed(ALLEGRO_EVENT, int);
		bool isKeyPressed(ALLEGRO_EVENT, std::vector<int>);
		
		/// Detects if a key is released
		/**
		 * Takes in either a single key or a vector of keys, and
		 * detects if that current key is being released in the allegro
		 * event
		**/
		bool isKeyReleased(ALLEGRO_EVENT ev, int key);
		bool isKeyReleased(ALLEGRO_EVENT ev, std::vector<int> keys);
		
		/// Detects if a key is down
		/**
		 * Similar to before, but does not require an allegro even
		**/
		bool isKeyDown(int);
		
	private:
		ALLEGRO_KEYBOARD_STATE keyState;
};
#endif
