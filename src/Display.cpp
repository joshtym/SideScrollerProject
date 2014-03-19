#include "Display.h"

Display::Display
{
	width = 800;
	height = 600;
}

Display::Display(int userGivenWidth, int userGivenHeight)
{
	width = userGivenWidth;
	height = userGivenHeight;
	
	display = al_create_display(width, height);
	
	if (!display)
	{
		
}

Display::~Display
{
}
