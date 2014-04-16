#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "Animation.h"

/// Class that handles the animation of the Player
/**
 * Using what is known as a spritesheet, this class handles the animation
 * of the player dependent on the direction of said player. If the player
 * is facing right for example, it loops through a series of 3 images in
 * constant succession which gives the appearance of animated movement.
 * Inherited from the animation class
**/
class SpriteSheet : public Animation
{
	public:
		/// Constructor
		/**
		 * Initializes frameCounter and switchFrame to their default
		 * values. Switch frame handles how quick the switch happens
		 * whilst frame counter handles the swap
		**/
		SpriteSheet();
		
		/// Destructor
		~SpriteSheet();
		
		/// Function to update the current Animation
		/**
		 * Updates the current animation of the player. Dependent
		 * on certain values, this will determine whether to switch
		 * to a new image, or continue it's current string dependent
		 * on whether the player is pressing new input values
		**/
		void update(Animation&);
		
	private:
		int frameCounter;
		int switchFrame;
};
#endif
