#include "GameScreen.h"
#include "BlockPlatform.h"
#include "BusObject.h"
#include "TitleScreen.h"
#include "SmallBlock.h"
#include "HalfInvisibleBlock.h"
#include "Spike.h"
#include "DeathScreen.h"


GameScreen::GameScreen()
{
	userPlayer = new Player();
	time = 0;
	imageXValue = 0;
	platformXValue = 0;
	isPlayerDead = false;
	score = 0;
	timeIncrementaleValue = 1;
	isNight = false;
}

GameScreen::~GameScreen()
{
	delete userPlayer;
	delete font;
}
 
void GameScreen::loadContent()
{
	font = al_load_ttf_font("./assets/fonts/font.ttf",62,0 );
	if((rand() % 2 + 1)>1)
	{
		bitmap = al_load_bitmap("./assets/imgFiles/backdropB.bmp");
	}
	else
	{
		bitmap = al_load_bitmap("./assets/imgFiles/backdropBa.bmp");
		isNight = true;
	}
	
	userPlayer->loadPlayer();
	obstacles.loadObstacles();

}

void GameScreen::unloadContent()
{
	userPlayer->unloadPlayer();
	obstacles.unloadObstacles();
	al_destroy_bitmap(bitmap);
}

void GameScreen::updateContent(ALLEGRO_EVENT ev)
{
	userPlayer->setStageSpeed(timeIncrementaleValue);
	speed = speed + timeIncrementaleValue;
	
	if(++time % 5 == 0)
		score++;
		
	imageXValue = speed*-2;
	platformXValue = (800 - speed*2);
	
	if (imageXValue < -800)
	{
		if(imageXValue < -1600)
		{
			imageXValue = 0;
			if(timeIncrementaleValue <= 5)
			{
				timeIncrementaleValue = timeIncrementaleValue + 0.5;
			}
			speed = 0;
		}
		else
			al_draw_bitmap(bitmap, (imageXValue+1600), 0, 0);
	}
	
	
	userPlayer->update(ev, input);
	obstacles.testForCollision(userPlayer, isPlayerDead);
	
	if (isPlayerDead)
		ScreenManager::GetInstance().addScreen(new DeathScreen());
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, imageXValue, 0, 0);
	obstacles.drawObstacles(timeIncrementaleValue);
	oss << "Score: ";
	oss << score;
	if(isNight) 
		al_draw_text(font, al_map_rgb(255,255,255), 525, 20,ALLEGRO_ALIGN_LEFT, oss.str().c_str());
	else 
		al_draw_text(font, al_map_rgb(0,0,0), 525, 20,ALLEGRO_ALIGN_LEFT, oss.str().c_str());
	userPlayer->draw(display);
	oss.str("");
	oss.clear();
	
	
}


