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
		virtual void setAlpha(double);
		double getAlpha();
		void setIsActive(bool);
		bool getIsActive();
		std::pair<int, int> &modifiableFrameCount();
		std::pair<int, int> &modifiableCurrentFrame();
		std::pair<int, int> &getFrameDimensions();
		
		ALLEGRO_BITMAP* Image();
		ALLEGRO_BITMAP*& returnSourceRectangle();
	
	protected:
		ALLEGRO_BITMAP *image, *sourceRectangle;
		std::string text;
		double position[2];
		double alpha;
		bool isActive;
		std::pair<int, int> frameCount;
		std::pair<int, int> currentFrame;
};
#endif
