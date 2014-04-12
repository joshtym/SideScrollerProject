#include "GameScreen.h"

GameScreen::GameScreen()
{
	userPlayer = new Player();
	cd.setPlayer(userPlayer);
}

GameScreen::~GameScreen()
{
	delete userPlayer;
}
 
void GameScreen::loadContent()
{
	bitmap = al_load_bitmap("./imgFiles/backdrop.bmp");
	userPlayer->loadPlayer();
}

void GameScreen::unloadContent()
{
	userPlayer->unloadPlayer();
}

void GameScreen::updateContent(ALLEGRO_EVENT ev)
{
	cd.calculateFloor();
	userPlayer->update(ev);
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, 0, 0, 0);
	userPlayer->draw();
}
