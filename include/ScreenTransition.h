#ifndef SCREENTRANSITION_H
#define SCREENTRANSITION_H

#include "Animation.h"

class ScreenTransition : public Animation
{
	public:
		ScreenTransition();
		~ScreenTransition();
		void unloadContent();
		void update(Animation&);
		void setIncrease(bool);
		
	private:
		double transitionSpeed;
		bool increase;
};
#endif
