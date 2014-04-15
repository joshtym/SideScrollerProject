#ifndef SPIKE_H
#define SPIKE_H

#include "ScrollerObstacle.h"

/// Class: Spike
/**
 * Purpose: Deadly spike for use in game 
**/
class Spike : public ScrollerObstacle
{	
	public:
		///Constructs a Spike
		Spike();
		
		///Destructs a Spike
		~Spike();

		/// Load Scroller obstacle
		/**
 		* Purpose: Loads the Obstacle assets  
		**/
		void loadScrollerObstacle();
};
#endif
 
