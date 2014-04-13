#include "GameScreen.h"
#include "Platform.h"
#include "TdObject.h"
#include <iostream>

GameScreen::GameScreen()
{
	userPlayer = new Player();
	userPlatform = new Platform();
	cd.setPlayer(userPlayer);
	time = 0;
	imageXValue = 0;
	platformXValue = 0;
}

GameScreen::~GameScreen()
{
	delete userPlayer;
	delete userPlatform;
}
 
void GameScreen::loadContent()
{
	bitmap = al_load_bitmap("./imgFiles/backdropB.bmp");
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
	//userPlayer->detectFloor(userPlatform->getTdo());
	
	//if(userPlayer->detectCollision(userPlatform->getTdo()))
	//	userPlayer->setXStatic();
	
	time++;
	
	imageXValue = time*-2;
	platformXValue = (800 - time*2);
	
	if (imageXValue < -800)
		if(imageXValue < -1600)
		{
			imageXValue = 0;
			time = 0;
		}
		else
			al_draw_bitmap(bitmap, (imageXValue+1600), 0, 0);
			
	userPlayer->update(ev, input);
	userPlatform->update(platformXValue, 200);
	
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, imageXValue, 0, 0);
	userPlayer->draw(display);
	userPlatform ->draw();
}
