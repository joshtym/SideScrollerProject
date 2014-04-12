#include "GameScreen.h"
#include "Platform.h"
#include "TdObject.h"

GameScreen::GameScreen()
{
	userPlayer = new Player();
	userPlatform = new Platform();
	cd.setPlayer(userPlayer);
}

GameScreen::~GameScreen()
{
	delete userPlayer;
	delete userPlatform;
}
 
void GameScreen::loadContent()
{
	bitmap = al_load_bitmap("./imgFiles/backdrop.bmp");
	userPlayer->loadPlayer();
	userPlatform ->loadPlatform();
}

void GameScreen::unloadContent()
{
	userPlayer->unloadPlayer();
	userPlatform ->unloadPlatform();
}

void GameScreen::updateContent(ALLEGRO_EVENT ev)
{
	cd.calculateFloor();
	userPlayer->detectFloor(userPlatform->getTdo());
	if(userPlayer->detectCollision(userPlatform->getTdo()))
	{
		userPlayer->setXStatic();
	}
	userPlayer->update(ev);
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, 0, 0, 0);
	userPlayer->draw(display);
	userPlatform ->draw();
}
