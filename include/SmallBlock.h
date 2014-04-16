#ifndef SMALLBLOCK_H
#define SMALLBLOCK_H

#include "ScrollerObstacle.h"

/// Class Small Block inherited from ScrollerObstacle
/**
 * Inherited object from ScrollerObstacle. Creates a Small Block
 * with specific dimensions from the imgFiles
**/
class SmallBlock : public ScrollerObstacle
{	
	public:
		/// Constructor for Small Block
		/**
		 * Initializes x and y values. x will start at 800. y is
		 * randomized so that it's near the stageFloor
		**/
		SmallBlock();
		
		/// Destructor
		~SmallBlock();
		
		/// Function to load obstacle
		/**
		 * Function loads image png and sets the correct dimensions
		 * for the obstacle
		**/
		void loadScrollerObstacle();
};
#endif
 
