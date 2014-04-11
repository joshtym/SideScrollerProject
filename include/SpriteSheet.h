#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "Animation.h"

class SpriteSheet : public Animation
{
	public:
		SpriteSheet();
		~SpriteSheet();
		
		void update(Animation&);
		
	private:
		int frameCounter;
		int switchFrame;
};
#endif
