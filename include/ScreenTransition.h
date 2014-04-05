#ifndef SCREENTRANSITION_H
#define SCREENTRANSITION_H

#include "Animation.h"

class ScreenTransition : public Animation
{
	public:
		ScreenTransition();
		~ScreenTransition();
		void loadContent(ALLEGRO_BITMAP* image, std::string text, double position[2]);
		void unloadContent();
		void update(InputManagement);
		
	private:
		double transitionSpeed;
		bool increase;
};
#endif
