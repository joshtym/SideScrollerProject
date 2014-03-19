#include "ScreenManager.h"
#include "TitleScreen.h"
#include "SplashScreen.h"

GameScreen *currentScreen, *newScreen;

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
	currentScreen = new TitleScreen();
}

void ScreenManager::addScreen(GameScreen *screen)
{
	newScreen = screen;
	currentScreen->unloadContent();
	currentScreen = newScreen;
	currentScreen->loadContent();
}

void ScreenManager::loadContent()
{
	currentScreen->loadContent();
}

void ScreenManager::update(ALLEGRO_EVENT ev)
{
	currentScreen->updateContent();
}

void ScreenManager::draw(ALLEGRO_DISPLAY *display)
{
	currentScreen->draw(display);
}
