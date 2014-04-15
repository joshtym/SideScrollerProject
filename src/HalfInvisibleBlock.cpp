#include "HalfInvisibleBlock.h"
 
HalfInvisibleBlock::HalfInvisibleBlock()
{
	scrollerObstacleDimension.setMinX(800);
	scrollerObstacleDimension.setMinY(200 + rand() %  188);
}
 
HalfInvisibleBlock::~HalfInvisibleBlock()
{
}
 
void HalfInvisibleBlock::loadScrollerObstacle()
{
	scrollerObstacleBitmap = al_load_bitmap("./assets/imgFiles/HalfInvisPlatform.png");
	scrollerObstacleDimension.setImgWidth(al_get_bitmap_width(scrollerObstacleBitmap));
	scrollerObstacleDimension.setImgHeight(al_get_bitmap_height(scrollerObstacleBitmap));
	
	scrollerObstacleDimension.updateValues();
}
