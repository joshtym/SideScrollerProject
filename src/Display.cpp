#include "Display.h"

// Allegro Inits
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

Display::Display()
{
	width = 800;
	height = 600;
	
	initialize();
}

Display::Display(int userGivenWidth, int userGivenHeight)
{
	width = userGivenWidth;
	height = userGivenHeight;
	
	initialize();
}
		
Display::~Display()
{
	al_destroy_display(display);
	al_uninstall_keyboard();
	al_uninstall_mouse();
}

void Display::initialize()
{
	al_init();
	
	if (!al_init())
	{
		al_show_native_message_box(0, "Error", "Error",
		"Cannot Initialize Allegro", 0, 0);
	}
	
	display = al_create_display(width, height);
	
	if (!display)
	{
		al_show_native_message_box(0, "Error", "Error with Display",
			"Cannot create display", 0, 0);
	}
	
	al_set_window_position(display, 100, 100);
	
	al_install_keyboard();
	al_install_mouse();
	
	al_init_image_addon();
	al_init_acodec_addon();
	
	al_init_font_addon();
	al_init_ttf_addon();
}

int Display::getWidth() const
{
	return width;
}

int Display::getHeight() const
{
	return height;
}

/*ALLEGRO_DISPLAY Display::*getAllegroDisplay() const 
{
	return display; 
}*/
