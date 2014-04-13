#include "ScreenManager.h"
#include "TitleScreen.h"
#include "SplashScreen.h"

ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
	delete currentScreen;
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
	transition.getAlpha() = 0;
	screenT.setIncrease(true);
	startOfTransition = true;
	newScreen = screen;
	transition.getIsActive() = true;
}

void ScreenManager::loadContent()
{
	startOfTransition = false;
	currentScreen->loadContent();
	transitionImage = al_load_bitmap("./imgFiles/black-wallpapers.jpg");
	double position[] = {0,0};
	transition.loadContent(transitionImage, position);
}

void ScreenManager::unloadContent()
{
	transition.unloadContent();
}

void ScreenManager::update(ALLEGRO_EVENT ev)
{
	if (!startOfTransition)
		currentScreen->updateContent(ev);
	else
		transitionHandler();
	
}

void ScreenManager::draw(ALLEGRO_DISPLAY *display)
{
	currentScreen->draw(display);
	
	if(startOfTransition)
		transition.draw(display, 0, 0);
}

void ScreenManager::transitionHandler()
{
	screenT.update(transition);
	if (transition.getAlpha() >= 255)
	{
		transition.getAlpha() = 255;
		currentScreen->unloadContent();
		delete currentScreen;
		currentScreen = newScreen;
		currentScreen->loadContent();
	}
	else if (transition.getAlpha() <= 0)
	{
		startOfTransition = false;
		transition.getIsActive() = false;
	}
}
