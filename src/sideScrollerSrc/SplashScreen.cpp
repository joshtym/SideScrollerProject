#include "SplashScreen.h"
#include "TitleScreen.h"

InputManagement splashInput;

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::loadContent()
{
	// Load bitmap
	bitmap = al_load_bitmap("./assets/imgFiles/splash.bmp");
}

void SplashScreen::unloadContent()
{
	// Destroy bitmap
	al_destroy_bitmap(bitmap);
}

void SplashScreen::updateContent(ALLEGRO_EVENT ev)
{
	// Is the "enter" key is pushed, go to title screen
	if (splashInput.isKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().addScreen(new TitleScreen());
}

void SplashScreen::draw(ALLEGRO_DISPLAY *display)
{
	// Draw bitmap
	al_draw_bitmap(bitmap, 0, 0, 0);
}
