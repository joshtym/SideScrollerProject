#include "GameScreen.h"
#include "TitleScreen.h"
#include "DeathScreen.h"


GameScreen::GameScreen()
{
	// Create new player
	userPlayer = new Player();
	
	// Assign default values
	time = 0;
	imageXValue = 0;
	platformXValue = 0;
	score = 0;
	timeIncrementaleValue = 1;
	isPlayerDead = false;
	isNight = false;
}

GameScreen::~GameScreen()
{
	delete userPlayer;
}
 
void GameScreen::loadContent()
{
	// Load in font
	font = al_load_ttf_font("./assets/fonts/font.ttf",62,0 );
	
	// Randomly decide whether to do a night or day bitmap
	if((rand() % 2) > 0)
	{
		bitmap = al_load_bitmap("./assets/imgFiles/backdropB.bmp");
	}
	else
	{
		bitmap = al_load_bitmap("./assets/imgFiles/backdropBa.bmp");
		isNight = true;
	}
	
	// Load player and obstacles
	userPlayer->loadPlayer();
	obstacles.loadObstacles();
}

void GameScreen::unloadContent()
{
	// Unload player, obstacles
	userPlayer->unloadPlayer();
	obstacles.unloadObstacles();
	
	// Destroy bitmap and font
	al_destroy_bitmap(bitmap);
	al_destroy_font(font);
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
			if(timeIncrementaleValue <= 8)
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
		ScreenManager::GetInstance().addScreen(new DeathScreen(score));
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	// Draw bitmap and obstacles to the screen
	al_draw_bitmap(bitmap, imageXValue, 0, 0);
	obstacles.drawObstacles(timeIncrementaleValue);
	
	// Using string streams, draw the score. Changes dependent on night
	oss << "Score: ";
	oss << score;
	if(isNight) 
		al_draw_text(font, al_map_rgb(255,255,255), 525, 20,ALLEGRO_ALIGN_LEFT, oss.str().c_str());
	else 
		al_draw_text(font, al_map_rgb(0,0,0), 525, 20,ALLEGRO_ALIGN_LEFT, oss.str().c_str());
	
	// Draw the player last
	userPlayer->draw(display);
	
	// Clear string stream
	oss.str("");
	oss.clear();
	
	
}


