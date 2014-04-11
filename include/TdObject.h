#ifndef TWODOBJECT_DETECTION_H
#define TWODOBJECT_DETECTION_H


class TdObject
{
	private:
		int x;
		int y;
		int yHeight;
		int xWidth;
	public:
		int getX();
		int getY();
		int getYHeight();
		int getXWidth();
		int setX();
		int setY();
		int setYHeight();
		int setXWidth();
};


#endif
