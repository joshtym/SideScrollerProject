#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>

class Player {

	public:
		Player();
		~Player();
		void LoadPlayer();
		
	private:
		ALLEGRO_BITMAP *playerBitmap;
		int x;
		int y;
		int speed = 5;
		
	public:
		move(ALLEGRO_EVENT);
		void draw();
};






#endif
