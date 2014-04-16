#ifndef SCROLLERHOLE_H
#define SCROLLERHOLE_H

#include "ScrollerObstacle.h"

/// Class Scroller Hole inherited from ScrollerObstacle
/**
 * Inherited object from ScrollerObstacle. Creates a Scroller Hole
 * with specific dimensions from the imgFiles
**/
class ScrollerHole : public ScrollerObstacle
{	
	public:
		/// Constructor for Scroller Hole
		/**
		 * Initializes x and y values. x will start at 800. y is
		 * randomized so that it's near the stageFloor
		**/
		ScrollerHole();
		
		/// Destructor
		~ScrollerHole();
		
		/// Function to load obstacle
		/**
		 * Function loads image png and sets the correct dimensions
		 * for the obstacle
		**/
		void loadScrollerObstacle();
};
#endif
