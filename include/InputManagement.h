#ifndef INPUTMANAGEMENT_H
#define INPUTMANAGEMENT_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <vector>

class InputManagement
{
	private:
		ALLEGRO_KEYBOARD_STATE keyState;
		
	public:
		InputManagement();
		~InputManagement();
		
		void update();
		
		bool isKeyPressed(ALLEGRO_EVENT, int);
		bool isKeyPressed(ALLEGRO_EVENT, std::vector<int>);
		
		bool isKeyReleased(ALLEGRO_EVENT ev, int key);
		bool isKeyReleased(ALLEGRO_EVENT ev, std::vector<int> keys);
		
		bool isKeyDown(int);
};
#endif
