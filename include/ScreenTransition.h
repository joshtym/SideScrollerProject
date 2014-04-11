#ifndef SCREENTRANSITION_H
#define SCREENTRANSITION_H

#include "Animation.h"

class ScreenTransition : public Animation
{
	public:
		ScreenTransition();
		~ScreenTransition();
		void loadContent(ALLEGRO_BITMAP*, std::string, double[]);
		void unloadContent();
		void update(InputManagement);
		void setAlpha(double);
		
	private:
		double transitionSpeed;
		bool increase;
};
#endif
