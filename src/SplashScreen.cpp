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
	bitmap = al_load_bitmap("./imgFiles/splash.bmp");
}

void SplashScreen::unloadContent()
{
	al_destroy_bitmap(bitmap);
}

void SplashScreen::updateContent(ALLEGRO_EVENT ev)
{
	if (splashInput.isKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().addScreen(new TitleScreen());
}

void SplashScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, 0, 0, 0);
}
