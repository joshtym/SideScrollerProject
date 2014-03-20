#include "Player.h"
 
 
Player::Player()
{
	 
	 
}
 
Player::~Player()
{
	 al_destroy_bitmap(playerBitmap);
	 
 }
 
Player::move(ALLEGRO_EVENT e)
{


	switch(e.keyboard.keycode)
	{
		case ALLEGRO_KEY_S:
			y += moveSpeed;
			break;
		case ALLEGRO_KEY_D:
			y -= moveSpeed;
			break;
		case ALLEGRO_KEY_R:
			x += moveSpeed;
			break;
		case ALLEGRO_KEY_A:
			x -= moveSpeed;
			break;
				
	}
	
}
 
Player::LoadPlayer()
{
	playerBitmap = al_load_bitmap("player.bmp");
}

void Player::draw()
{
	al_draw_bitmap(playerBitmap, x, y, 0);

}
