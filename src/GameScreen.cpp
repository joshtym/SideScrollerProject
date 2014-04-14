#include "GameScreen.h"
#include "BlockPlatform.h"
#include "BusObject.h"
#include "TitleScreen.h"
#include "SmallBlock.h"
#include "HalfInvisibleBlock.h"


GameScreen::GameScreen()
{
	userPlayer = new Player();
	userPlatform = new HalfInvisibleBlock();
	time = 0;
	imageXValue = 0;
	platformXValue = 0;
	playerIsDead = false;
	score = 0;
	timeIncrementaleValue = 1;
}

GameScreen::~GameScreen()
{
	delete userPlayer;
	delete userPlatform;
	delete font;
}
 
void GameScreen::loadContent()
{
	font = al_load_ttf_font("./assets/fonts/font.ttf",62,0 );
	bitmap = al_load_bitmap("./assets/imgFiles/backdropB.bmp");
	bitmap1 = al_load_bitmap("./assets/imgFiles/backdropA.bmp");
	userPlayer->loadPlayer();
	userPlatform->loadScrollerObstacle();

}

void GameScreen::unloadContent()
{
	userPlayer->unloadPlayer();
	userPlatform ->unloadScrollerObstacle();
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
			if(timeIncrementaleValue < 7)
			{
				timeIncrementaleValue = timeIncrementaleValue + 0.5;
			}
			speed = 0;
		}
		else
			al_draw_bitmap(bitmap, (imageXValue+1600), 0, 0);
	}
	
	
	userPlayer->update(ev, input);
	userPlatform->update(platformXValue);
	isCollidingWithObject = cd.checkForCollision(userPlayer->getCurrentDimensions(), userPlatform->getCurrentDimensions());
	isCollidingWithEdge = cd.checkForPlayerAtEdgeOfScreen(userPlayer->getCurrentDimensions());
	
	if (isCollidingWithObject)
		isCollidingOnPlatformTop = cd.isOnTopPlatform(userPlayer->getCurrentDimensions(), userPlatform->getCurrentDimensions());
	else
		isCollidingOnPlatformTop = false;
		
	userPlayer->setIsOnPlatform(isCollidingOnPlatformTop);
	
	
	if (isCollidingWithObject && isCollidingWithEdge)
	{
		//if(!(isCollidingOnPlatformTop))
			ScreenManager::GetInstance().addScreen(new TitleScreen());
	}
	else if (isCollidingWithObject)
		cd.fixCollision(userPlayer->getCurrentDimensions(), userPlatform->getCurrentDimensions());
	else if (isCollidingWithEdge)
		cd.fixCollisionAtEdgeOfScreen(userPlayer->getCurrentDimensions());
}

void GameScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, imageXValue, 0, 0);
	userPlatform ->draw();
	oss << "Score: ";
	oss << score;
	al_draw_text(font, al_map_rgb(0,0,0), 525, 20,ALLEGRO_ALIGN_LEFT, oss.str().c_str());
	userPlayer->draw(display);
	oss.str("");
	oss.clear();
	
	
}


