#ifndef GAMESCREENINTERFACE_H
#define GAMESCREENINTERFACE_H

#include <allegro5/allegro.h>

class GameScreenInterface
{
	public:
		GameScreenInterface();
		~GameScreenInterface();
		
		virtual void loadContent();
		virtual void unloadContent();
		virtual void updateContent(ALLEGRO_EVENT ev);
		virtual void draw(ALLEGRO_DISPLAY*);
};
#endif
