#include <iostream>
#include <stdio.h>
#include "BlockPlatform.h"
 
BlockPlatform::BlockPlatform()
{
	srand(time(0));
	platformDimension.setMinX(800);
	platformDimension.setMinY(250 + rand() % 200);
}
 
BlockPlatform::~BlockPlatform()
{
}
 
void BlockPlatform::loadPlatform()
{
	platformBitmap = al_load_bitmap("./assets/imgFiles/basicPlatform1.png");
	platformBitmap2 = al_load_bitmap("./assets/imgFiles/basicPlatformd.png");
	platformDimension.setImgWidth(al_get_bitmap_width(platformBitmap));
	platformDimension.setImgHeight(al_get_bitmap_height(platformBitmap));
	
	platformDimension.updateValues();
}
