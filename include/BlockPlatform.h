#ifndef BLOCKPLATFORM_H
#define BLOCKPLATFORM_H

#include "ScrollerObstacle.h"

/// Block platform inherited from ScrollerObstacle
/**
 * Inherited object from ScrollerObstacle. Creates a standard block
 * platform with specific dimensions from the imgFiles
**/
class BlockPlatform : public ScrollerObstacle
{
	public:
		/// Constructor for BlockPlatform
		/**
		 * Initializes x and y values. x will start at 800. y is
		 * randomized so that it's near the stageFloor
		**/
		BlockPlatform();
		
		/// Destructor
		~BlockPlatform();
		
		/// Function to load obstacle
		/**
		 * Function loads image png and sets the correct dimensions
		 * for the obstacle
		**/
		void loadScrollerObstacle();
};
#endif
 
