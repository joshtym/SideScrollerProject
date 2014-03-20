#include "GameScreen.h"
#include "Player.h"


GameScreen::GameScreen()
{
	
}

GameScreen::~GameScreen()
{
	
}

void GameScreen::loadContent()
{
	userPlayer.loadPlayer();
}

void GameScreen::unloadContent()
{
	userPlayer.unloadPlayer();
}

void GameScreen::updateContent(ALLEGRO_EVENT ev)
{
	userPlayer.move(ev);
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	userPlayer.draw();
}
