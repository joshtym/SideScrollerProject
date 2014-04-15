#ifndef FIREHYDRANT_H
#define FIREHYDRANT_H

#include "ScrollerObstacle.h"

/// Class: Fire Hydrant
/**
 * Purpose: Fire Hydrant for use in game 
**/
class FireHydrant : public ScrollerObstacle
{	
	public:
		///Constructs a Fire Hydrant
		Spike();
		
		///Destructs a Fire Hydrant
		~Spike();

		/// Load Scroller obstacle
		/**
 		* Purpose: Loads the Fire Hydrant Obstacle assets  
		**/
		void loadScrollerObstacle();
};
#endif
 
