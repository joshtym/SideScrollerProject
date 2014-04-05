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
#include "Player.h"

class CollisionDetection
{
	private:
		Player* p;
		
		
	public:
		CollisionDetection();
		CollisionDetection(Player*);
		~CollisionDetection();
		void calculateFloor();
		void setPlayer(Player*);
		

};



#endif
