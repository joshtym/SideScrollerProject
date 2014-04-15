#ifndef ANIMATION_H
#define ANIMATION_H

#include "InputManagement.h"
#include <allegro5/allegro_image.h>

class Animation
{
	public:
		Animation();
		~Animation();
		void loadContent(ALLEGRO_BITMAP*, double[]);
		void unloadContent();
		virtual void update(Animation&);
		void draw(ALLEGRO_DISPLAY*, double, double);
		
		double& getAlpha();
		bool& getIsActive();
		
		std::pair<int, int> &modifiableFrameCount();
		std::pair<int, int> &modifiableCurrentFrame();
		std::pair<int, int> &getFrameDimensions();
		
		ALLEGRO_BITMAP* Image();
		ALLEGRO_BITMAP*& returnSourceRectangle();
	
	protected:
		ALLEGRO_BITMAP *image, *sourceRectangle;
		double position[2];
		double alpha;
		bool isActive;
		std::pair<int, int> frameCount;
		std::pair<int, int> currentFrame;
};
#endif
