#ifndef ANIMATION_H
#define ANIMATION_H

#include "InputManagement.h"
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

class Animation
{
	public:
		Animation();
		~Animation();
		virtual void loadContent(ALLEGRO_BITMAP* image, std::string text, double position[2]);
		virtual void unloadContent();
		virtual void update(InputManagement);
		void draw(ALLEGRO_DISPLAY *display);
	
	protected:
		ALLEGRO_BITMAP *image, *sourceRectangle;
		ALLEGRO_FONT *font;
		std::string text;
		double position[2];
		double alpha;
		bool isActive;
};
#endif
