#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>

class Player 
{
	private:
		ALLEGRO_BITMAP *playerBitmap;
		int x;
		int y;
		int tick = 0;
		int moveSpeed = 5;
		bool flip = false;
		void setX(int);
		void setY(int);
		
	public:
		Player();
		~Player();
		void loadPlayer();
		void unloadPlayer();
		void move(ALLEGRO_EVENT);
		void draw();
		void gravityTick();
		
};
#endif
