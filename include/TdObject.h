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
		TdObject();
		int getX();
		int getY();
		int getYHeight();
		int getXWidth();
		int setX(int);
		int setY(int);
		int setYHeight(int);
		int setXWidth(int);
};


#endif
