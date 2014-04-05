#include "ScreenManager.h"
#include "TitleScreen.h"
#include "SplashScreen.h"

GameScreenInterface *currentScreen;

ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
}

ScreenManager::ScreenManager(const ScreenManager& screen)
{
}

ScreenManager &ScreenManager::operator=(const ScreenManager& newScreen)
{
}

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager newInstance;
	return newInstance;
}

void ScreenManager::Initialize()
{
	currentScreen = new SplashScreen();
}

void ScreenManager::addScreen(GameScreenInterface *screen)
{ 
	currentScreen->unloadContent();
	delete currentScreen;
	currentScreen = screen;
	currentScreen->loadContent();
}

void ScreenManager::loadContent()
{
	currentScreen->loadContent();
}

void ScreenManager::update(ALLEGRO_EVENT ev)
{
	currentScreen->updateContent(ev);
	
}

void ScreenManager::draw(ALLEGRO_DISPLAY *display)
{
	currentScreen->draw(display);
}
