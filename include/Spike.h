#ifndef SPIKE_H
#define SPIKE_H

#include "ScrollerObstacle.h"

/// Class Spike inherited from ScrollerObstacle
/**
 * Inherited object from ScrollerObstacle. Creates a Spike
 * with specific dimensions from the imgFiles
**/
class Spike : public ScrollerObstacle
{	
	public:
		/// Constructor for Spike
		/**
		 * Initializes x and y values. x will start at 800. y is
		 * randomized so that it's near the stageFloor
		**/
		Spike();
		
		///Destructor
		~Spike();

		/// Function to load obstacle
		/**
		 * Function loads image png and sets the correct dimensions
		 * for the obstacle
		**/
		void loadScrollerObstacle();
};
#endif
 
