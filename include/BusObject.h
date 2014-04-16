#ifndef BUSOBJECT_H
#define BUSOBJECT_H

#include "ScrollerObstacle.h"

/// Bus object inherited from ScrollerObstacle
/**
 * Inherited object from ScrollerObstacle. Creates a bus object
 * with specific dimensions from the imgFiles
**/
class BusObject : public ScrollerObstacle
{	
	public:
		/// Constructor for BusObject
		/**
		 * Initializes x and y values. x will start at 800. y is
		 * randomized so that it's near the stageFloor
		**/
		BusObject();
		
		/// Destructor
		~BusObject();
		
		/// Function to load obstacle
		/**
		 * Function loads image png and sets the correct dimensions
		 * for the obstacle
		**/
		void loadScrollerObstacle();
};
#endif
 
