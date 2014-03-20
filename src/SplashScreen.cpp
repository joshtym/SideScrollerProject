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
	font = al_load_font("arial.ttf", 30, 0);
	
	bitmap = al_load_bitmap("splash.bmp");
}

void SplashScreen::unloadContent()
{
	al_destroy_font(font);
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
	al_draw_text(font, al_map_rgb(0, 0, 255), 100, 100, 0, "SplashScreen");
}
