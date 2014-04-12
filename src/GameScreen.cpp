#include "GameScreen.h"
#include "BlockPlatform.h"
#include "BusObject.h"
#include "TitleScreen.h"


GameScreen::GameScreen()
{
	userPlayer = new Player();
	userPlatform = new BlockPlatform();
	time = 0;
	imageXValue = 0;
	platformXValue = 0;
	playerIsDead = false;
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon
	font = al_load_ttf_font("./src/font.ttf",62,0 );
}

GameScreen::~GameScreen()
{
	delete userPlayer;
	delete userPlatform;
	delete font;
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
	if(time % 5 == 0)
		score++;
	
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
	
	isCollidingOnPlatformTop = cd.isOnTopPlatform(userPlayer->getCurrentDimensions(), userPlatform->getCurrentDimensions());
	userPlayer->setIsOnPlatform(isCollidingOnPlatformTop);
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
	userPlatform ->draw();
	oss << "Score: ";
	oss << score;
	al_draw_text(font, al_map_rgb(0,0,0), 550, (20),ALLEGRO_ALIGN_LEFT, oss.str().c_str());
	userPlayer->draw(display);
	oss.str("");
	oss.clear();
	
	
}


