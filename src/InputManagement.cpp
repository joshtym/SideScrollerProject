#include "InputManagement.h"

InputManagement::InputManagement()
{
}

InputManagement::~InputManagement()
{
}

void InputManagement::update()
{
	al_get_keyboard_state(&keyState);
}

bool InputManagement::isKeyPressed(ALLEGRO_EVENT ev, int key)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		if (ev.keyboard.keycode == key)
			return true;
	
	return false;
}

bool InputManagement::isKeyPressed(ALLEGRO_EVENT ev, std::vector<int> keys)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		for (int i = 0; i < keys.size(); i++)
			if (ev.keyboard.keycode == keys[i])
				return true;
	
	return false;
}

bool InputManagement::isKeyReleased(ALLEGRO_EVENT ev, int key)
{
	if (ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		if (ev.keyboard.keycode == key)
			return true;
	}
	
	return false;
}

bool InputManagement::isKeyReleased(ALLEGRO_EVENT ev, std::vector<int> keys)
{
	if (ev.type == ALLEGRO_EVENT_KEY_UP)
		for (int i = 0; i < keys.size(); i++)
			if (ev.keyboard.keycode == keys[i])
				return true;
	
	return false;
}

bool InputManagement::isKeyDown(int key)
{
	if(al_key_down(&keyState, key))
		return true;
	return false;
}
