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
	// Load bitmap
	bitmap = al_load_bitmap("./assets/imgFiles/title.bmp");
}

void TitleScreen::unloadContent()
{
	// Destroy bitmap
	al_destroy_bitmap(bitmap);
}

void TitleScreen::updateContent(ALLEGRO_EVENT ev)
{
	// If the 'N' key is hit, start a new game
	if (titleInput.isKeyPressed(ev, ALLEGRO_KEY_N))
		ScreenManager::GetInstance().addScreen(new GameScreen());
}

void TitleScreen::draw(ALLEGRO_DISPLAY *display)
{
	// Draw bitmap
	al_draw_bitmap(bitmap, 0, 0, 0);
}
