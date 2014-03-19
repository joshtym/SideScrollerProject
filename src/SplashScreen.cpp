#include "SplashScreen.h"
#include "TitleScreen.h"

InputManager splashInput;

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::loadContent()
{
	font = al_load_font("COMICATE.ttf", 30, 0);
}

void SplashScreen::unloadContent()
{
	al_destroy_font(font);
}

void SplashScreen::update(ALLEGRO_EVENT ev)
{
	if (splashInput.isKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().addScreen(new TitleScreen());
}

void SplashScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_text(font, al_map_rgb(0, 0, 255), 100, 100, 0, "SplashScreen");
}
