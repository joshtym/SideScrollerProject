#include "DeathScreen.h"
#include "TitleScreen.h"
#include "GameScreen.h"

InputManagement deathInput;

DeathScreen::DeathScreen()
{
}

DeathScreen::~DeathScreen()
{
}

void DeathScreen::loadContent()
{
	bitmap = al_load_bitmap("./assets/imgFiles/deathScreen.bmp");
}

void DeathScreen::unloadContent()
{
	al_destroy_bitmap(bitmap);
}

void DeathScreen::updateContent(ALLEGRO_EVENT ev)
{
	if (deathInput.isKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().addScreen(new GameScreen());
}

void DeathScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, 0, 0, 0);
}
