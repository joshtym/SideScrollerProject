#include "Spike.h"
 
Spike::Spike()
{
	// Assign default values
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(250 + rand() % (388 - static_cast<int>(scrollerObstacleDimension.getImgHeight()) - 250));
	isDeadly = true;
	isBeingDrawn = false;
}
 
Spike::~Spike()
{
}
 
void Spike::loadScrollerObstacle()
{
	// Load bitmap
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/spikes.png");
	
	// Assign imgWidth and imgHeight
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	// Update object dimensions
	scrollerObstacleDimension.updateValues();
	
}
