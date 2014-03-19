#include "TitleScreen.h"
#include "SplashScreen.h"
#include <iostream>

InputManager titleInput;

TitleScreen::TitleScreen()
{
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::loadContent()
{
	font = al_load_font("COMICATE.ttf", 30, 0);
}

void TitleScreen::unloadContent()
{
	al_destroy_font(font);
}

void TitleScreen::update(ALLEGRO_EVENT ev)
{
	if (titleInput.isKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().addScreen(new SplashScreen());
}

void TitleScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_text(font, al_map_rgb(255, 0, 0), 100, 100, 0, "TitleScreen");
}
