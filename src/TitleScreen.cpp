#include "TitleScreen.h"
#include "SplashScreen.h"
#include "GameScreen.h"

InputManagement titleInput;

TitleScreen::TitleScreen()
{
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::loadContent()
{
	bitmap = al_load_bitmap("./imgFiles/title.bmp");
}

void TitleScreen::unloadContent()
{
}

void TitleScreen::updateContent(ALLEGRO_EVENT ev)
{
	if (titleInput.isKeyPressed(ev, ALLEGRO_KEY_N))
		ScreenManager::GetInstance().addScreen(new GameScreen());
}

void TitleScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, 0, 0, 0);
}
