#ifndef TWODOBJECT_DETECTION_H
#define TWODOBJECT_DETECTION_H


class TdObject
{
	private:
		int x;
		int y;
		int yHeight;
		int xWidth;
		
		int xMin;
		int xMax;
		int yMin;
		int yMax;

	
	public:
		TdObject();
		int getX();
		int getY();
		int getYHeight();
		int getXWidth();
		int getMinX();
		int getMaxX();
		int getMinY();
		int getMaxY();		
		int setX(int);
		int setY(int);
		int setYHeight(int);
		int setXWidth(int);
		bool isColliding(TdObject*);
		void calcMixMax();
};


#endif
