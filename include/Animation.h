#ifndef ANIMATION_H
#define ANIMATION_H

#include "InputManagement.h"
#include <allegro5/allegro_image.h>

/// Class that handles the different Animation
/**
 * Class handles the different animations from screen transitions
 * to dealing with sprite animations from the player file
**/
class Animation
{
	public:
		/// Constructor and Destructor for Animation
		Animation();
		~Animation();
		
		/// Virtual function that updates the animation
		/**
		 * Based on the child class, this function is altered to update
		 * the animation accordingly.
		**/
		virtual void update(Animation&);
		
		/// Function that loads the animation content
		/**
		 * Function loads all the required resources to handle
		 * animation. Loads up the image and sets the double
		 * value according to values given
		**/
		void loadContent(ALLEGRO_BITMAP*, double[]);
		
		/// Function to unload all content related to animation
		/**
		 * Unloads all the content related to animation including
		 * destroying all bitmaps, and defaulting values to 0
		**/
		void unloadContent();
		
		/// Function to draw the animation to the screen
		/**
		 * Function that does exactly as described. Draw the animation
		 * to the screen
		**/
		void draw(ALLEGRO_DISPLAY*, double, double);
		
		/// Setters and getters
		/// This function acts as a multi-functional function
		/**
		 * By allowing for return of a reference paramater, this allows
		 * us to assign this function to several jobs that include
		 * getting the current alpha variable as well as setting
		 * said variable
		**/
		double& getAlpha();
		
		/// This function acts as a multi-functional function
		/**
		 * By allowing for return of a reference paramater, this allows
		 * us to assign this function to several jobs that include
		 * getting the current isActive variable as well as setting
		 * said variable
		**/
		bool& getIsActive();
		
		/// Function that allows us to return and modify the frameCount
		/**
		 * By allowing for return of a reference parameter, this allows
		 * us to assign this function to several jobs that include
		 * getting the current frameCount variable as well as setting
		 * said variable
		**/
		std::pair<int, int> &modifiableFrameCount();
		
		/// Function that allows us to return and modify the currentFrame
		/**
		 * By allowing for return of a reference parameter, this allows
		 * us to assign this function to several jobs that include
		 * getting the currentFrame variable as well as setting
		 * said variable
		**/
		std::pair<int, int> &modifiableCurrentFrame();
		
		/// Function that allows us to return and modify the frameDimensions
		/**
		 * By allowing for return of a reference parameter, this allows
		 * us to assign this function to several jobs that include
		 * getting the frameDimensions variable as well as setting
		 * said variable
		**/
		std::pair<int, int> &getFrameDimensions();
		
		/// Function that allows us to return and modify the Image
		/**
		 * By allowing for return of a reference parameter, this allows
		 * us to assign this function to several jobs that include
		 * getting the Allegro bitmap image variable as well as setting
		 * said variable
		**/
		ALLEGRO_BITMAP* Image();
		
		/// Function that allows us to return and modify the SourceRectangle
		/**
		 * By allowing for return of a reference parameter, this allows
		 * us to assign this function to several jobs that include
		 * getting the Allegro bitmap sourceRectangle variable as well as setting
		 * said variable
		**/
		ALLEGRO_BITMAP*& returnSourceRectangle();
	
	protected:
		/// Private data members that allow for manipulation of animation
		ALLEGRO_BITMAP *image, *sourceRectangle;
		double position[2];
		double alpha;
		bool isActive;
		std::pair<int, int> frameCount;
		std::pair<int, int> currentFrame;
};
#endif
