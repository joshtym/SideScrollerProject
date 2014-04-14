#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include "ObjectDimensions.h"

class CollisionDetection
{
	public:
		CollisionDetection();
		~CollisionDetection();
		
		bool checkForCollision(ObjectDimensions, ObjectDimensions);
		bool checkForPlayerAtEdgeOfScreen(ObjectDimensions);
		void fixCollision(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionAtEdgeOfScreen(ObjectDimensions&);
		
	private:
		void fixCollisionLeftSide(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionRightSide(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionTopPlatform(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionBottomPlatform(ObjectDimensions&, ObjectDimensions&);
};



#endif
