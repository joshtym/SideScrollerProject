#ifndef SCROLLEROBSTACLE_H
#define SCROLLEROBSTACLE_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <cstdlib>
#include "ObjectDimensions.h"


/// Class: Scroller Obstacle
/**
 * Purpose: Interface for controlling how 
 * obstacles are loaded, drawn, and updated   
**/
class ScrollerObstacle
{
	public:
		/// Load Scroller obstacle
		/**
 		* Purpose: Loads the Image file for later display   
		**/
		virtual void loadScrollerObstacle() = 0;

		/// Unloads Scroller obstacle
		/**
 		* Purpose: unloads the assets for memory freeing   
		**/
		virtual void unloadScrollerObstacle();

		/// Update Scroller obstacle
		/**
 		* Purpose: Updates the location on obstacle   
		**/
		virtual void update(double);

		/// Draw Scroller obstacle
		/**
 		* Purpose: Draws the Image file to screen  
		**/
		virtual void draw(double);

		/// Get Obstacles Dimensions
		/**
 		* Purpose: Gets the current dimensions for use by 			* collision detection  
		**/
		virtual ObjectDimensions& getCurrentDimensions();

		/// Reset X And Y
		/**
 		* Purpose: Resets X and Y 
		**/
		void resetXAndYValues();

		/// getIsDeadly
		/**
 		* Purpose: Returns isdeadly status 
		**/
		bool getIsDeadly();

		/// getIsBeingDrawn
		/**
 		* Purpose: Returns isBeingDrawn status 
		**/
		bool getIsBeingDrawn();
		
	protected:
		ALLEGRO_BITMAP *scrollerObstacleBitmap;
		ObjectDimensions scrollerObstacleDimension;
		bool isTransparent;
		bool isDeadly;
		bool isBeingDrawn;
};
#endif
 
