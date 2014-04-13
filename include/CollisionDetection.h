#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

// Allegro Inits
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "ObjectDimensions.h"

class CollisionDetection
{
	public:
		CollisionDetection();
		~CollisionDetection();
		
		bool checkForCollision(ObjectDimensions, ObjectDimensions);
		void fixCollision(ObjectDimensions&, ObjectDimensions&);
		
	private:
		void fixCollisionLeftSide(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionRightSide(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionTopPlatform(ObjectDimensions&, ObjectDimensions&);
		void fixCollisionBottomPlatform(ObjectDimensions&, ObjectDimensions&);
};



#endif
