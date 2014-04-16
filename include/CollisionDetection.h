#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include "ObjectDimensions.h"

/// Class to handle any and all Collision Detection
/**
 * This class handles all collision whether it be with the screen
 * or a secondary obstacle and adjusts the objects dimensions accordingly
**/
class CollisionDetection
{
	public:
		/// Contructor for CollisionDetection
		CollisionDetection();
		
		/// Destructor for CollisionDetection
		~CollisionDetection();
		
		/// Detects for collision of two objects
		/**
		 * Takes the dimensions of the two objects to be checked
		 * and indicates whether the two objects are currently in
		 * collision. It essentially checks if at any point, the 
		 * two objects are "overlapping" hence firing off collision
		**/
		bool checkForCollision(ObjectDimensions, ObjectDimensions);
		
		/// Check if player is at edge of screen
		/**
		 * Does a quick check to see if the objects current dimensions
		 * are at the end of screen
		**/
		bool checkForPlayerAtEdgeOfScreen(ObjectDimensions);
		
		/// Fixes collision between objects
		/**
		 * Uses helper functions adjust the object dimensions of
		 * the player to ensure that the player is not "passing through"
		 * the object
		**/
		void fixCollision(ObjectDimensions&, ObjectDimensions&);
		
		/// Fixes collision at edge of screen
		/**
		 * Adjusts the players dimensiosn accordingly so it's
		 * not going past the screen
		**/
		void fixCollisionAtEdgeOfScreen(ObjectDimensions&);
		
		/// Checks if player is on top of object
		/**
		 * Does a quick check to see if the object dimensions
		 * of the player are on top of a platform. This changes
		 * how we want to deal with the collision
		**/
		bool isOnTopPlatform(ObjectDimensions&, ObjectDimensions&);
		
	private:
		/// Helper functions
		/**
		 * All the following functions help "fixCollision" in fixing
		 * the collisions between the player and the platform
		**/
		void fixCollisionLeftSide(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionRightSide(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionTopPlatform(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionBottomPlatform(ObjectDimensions&, ObjectDimensions&);
};



#endif
