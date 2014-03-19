#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>				//Our primitive header file

int main(void)
{
	int width = 800;
	int height = 600;

	ALLEGRO_DISPLAY *display = NULL;
 
	if(!al_init())										//initialize Allegro
		return -1;
 
	display = al_create_display(width, height);			//create our display object

	if(!display)										//test display object
		return -1;
 
	al_init_primitives_addon();

	al_draw_line(100, 100, width - 100, 100, al_map_rgb(255, 0, 0), 1);
	al_draw_line(50, 200, width - 50, 200, al_map_rgb(0, 0, 255), 5);
	al_draw_line(0, 300, width, 300, al_map_rgb(255, 0, 255), 10);
	al_draw_line(50, 50, 50, 400, al_map_rgb(0, 255, 0), 3);
	al_draw_line(50, 200, width - 50, 400, al_map_rgb(0, 0, 255), 5);

	al_flip_display();
 
	al_rest(4.0);
 
	al_destroy_display(display);						//destroy our display object

	return 0;
}
