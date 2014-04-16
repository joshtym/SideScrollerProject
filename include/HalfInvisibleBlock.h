#ifndef HALFINVISIBLEBLOCK_H
#define HALFINVISIBLEBLOCK_H

#include "ScrollerObstacle.h"

/// Class Half Invisible Block inherited from ScrollerObstacle
/**
 * Inherited object from ScrollerObstacle. Creates a half invisible
 * block with specific dimensions from the imgFiles
**/
class HalfInvisibleBlock : public ScrollerObstacle
{	
	public:
		/// Constructor for Half Invisible Block
		/**
		 * Initializes x and y values. x will start at 800. y is
		 * randomized so that it's near the stageFloor
		**/
		HalfInvisibleBlock();
		
		/// Destructor
		~HalfInvisibleBlock();
		
		/// Function to load obstacle
		/**
		 * Function loads image png and sets the correct dimensions
		 * for the obstacle
		**/
		void loadScrollerObstacle();
};
#endif
 
