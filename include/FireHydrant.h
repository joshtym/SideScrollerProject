#ifndef FIREHYDRANT_H
#define FIREHYDRANT_H

#include "ScrollerObstacle.h"

/// Class Fire Hydrant inherited from ScrollerObstacle
/**
 * Inherited object from ScrollerObstacle. Creates a fire hydrant
 * with specific dimensions from the imgFiles
**/
class FireHydrant : public ScrollerObstacle
{	
	public:
		/// Constructor for FireHydrant
		/**
		 * Initializes x and y values. x will start at 800. y is
		 * randomized so that it's near the stageFloor
		**/
		FireHydrant();
		
		/// Destructor
		~FireHydrant();

		/// Function to load obstacle
		/**
		 * Function loads image png and sets the correct dimensions
		 * for the obstacle
		**/
		void loadScrollerObstacle();
};
#endif
 
