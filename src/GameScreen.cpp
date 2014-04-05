#include "GameScreen.h"

GameScreen::GameScreen()
{	
}

GameScreen::~GameScreen()
{
}
 
void GameScreen::loadContent()
{
	bitmap = al_load_bitmap("./imgFiles/backdrop.bmp");
	userPlayer.loadPlayer();
}

void GameScreen::unloadContent()
{
	userPlayer.unloadPlayer();
}

void GameScreen::updateContent(ALLEGRO_EVENT ev)
{
	userPlayer.jumpTick();
	userPlayer.gravityTick();
	userPlayer.move(ev);
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, 0, 0, 0);
	userPlayer.draw();
}
