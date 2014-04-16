#include "DeathScreen.h"
#include "TitleScreen.h"
#include "GameScreen.h"

InputManagement deathInput;

DeathScreen::DeathScreen(int score)
{
	// Constructor assigns given score to it's value
	Finalscore = score;
}

DeathScreen::~DeathScreen()
{
}

void DeathScreen::loadContent()
{
	// Load font and bitmap
	font = al_load_ttf_font("./assets/fonts/font.ttf",62,0 );
	bitmap = al_load_bitmap("./assets/imgFiles/deathScreen.bmp");
}

void DeathScreen::unloadContent()
{
	// Destroy bitmap and font
	al_destroy_bitmap(bitmap);
	al_destroy_font(font);
}

void DeathScreen::updateContent(ALLEGRO_EVENT ev)
{
	// If the key hit is enter, try the game again
	if (deathInput.isKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().addScreen(new GameScreen());
}

void DeathScreen::draw(ALLEGRO_DISPLAY *display)
{
	// Using string streams, draw both the bitmap and score to the screen
	al_draw_bitmap(bitmap, 0, 0, 0);
	oss << "Total Score: ";
	oss << Finalscore;
	
	al_draw_text(font, al_map_rgb(255,255,255), 220, 500,ALLEGRO_ALIGN_LEFT, oss.str().c_str());
	oss.str("");
	oss.clear();
}
