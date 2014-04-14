#include "GameScreen.h"
#include "BlockPlatform.h"
#include "BusObject.h"
#include "TitleScreen.h"
#include <iostream>

GameScreen::GameScreen()
{
	userPlayer = new Player();
	userPlatform = new BusObject();
	time = 0;
	imageXValue = 0;
	platformXValue = 0;
	playerIsDead = false;
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
	al_destroy_bitmap(bitmap);
}

void GameScreen::updateContent(ALLEGRO_EVENT ev)
{
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
	userPlatform->update(platformXValue);
	
	isCollidingWithObject = cd.checkForCollision(userPlayer->getCurrentDimensions(), userPlatform->getCurrentDimensions());
	isCollidingWithEdge = cd.checkForPlayerAtEdgeOfScreen(userPlayer->getCurrentDimensions());
	
	if (isCollidingWithObject && isCollidingWithEdge)
		ScreenManager::GetInstance().addScreen(new TitleScreen());
	else if (isCollidingWithObject)
		cd.fixCollision(userPlayer->getCurrentDimensions(), userPlatform->getCurrentDimensions());
	else if (isCollidingWithEdge)
		cd.fixCollisionAtEdgeOfScreen(userPlayer->getCurrentDimensions());
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, imageXValue, 0, 0);
	userPlayer->draw(display);
	userPlatform ->draw();
}
