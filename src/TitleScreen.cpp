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
	font = al_load_font("w.ttf", 30, 0);
	bitmap = al_load_bitmap("splash.bmp");
}

void TitleScreen::unloadContent()
{
	al_destroy_font(font);
}

void TitleScreen::updateContent(ALLEGRO_EVENT ev)
{
	if (titleInput.isKeyPressed(ev, ALLEGRO_KEY_N))
		ScreenManager::GetInstance().addScreen(new GameScreen());
}

void TitleScreen::draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(bitmap, 0, 0, 0);
	al_draw_text(font, al_map_rgb(255, 0, 0), 350, 30, 0, "Scroller");
	al_draw_text(font, al_map_rgb(255, 255, 0), 350, 230, 0, "New Game (n)");
	al_draw_text(font, al_map_rgb(255, 255, 0), 350, 270, 0, "Exit (esc)");
}
