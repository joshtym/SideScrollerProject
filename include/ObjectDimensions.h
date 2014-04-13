#ifndef OBJECTDIMENSIONS_H
#define OBJECTDIMENSIONS_H

enum Direction {DOWN, LEFT, RIGHT, UP};

class ObjectDimensions
{	
	public:
		ObjectDimensions();
		~ObjectDimensions();
		
		double getMinX();
		double getMinY();
		double getMaxX();
		double getMaxY();
		double getImgWidth();
		double getImgHeight();
		Direction getCurrentDirection();
		
		void setMinX(double);
		void setMinY(double);
		void setMaxX(double);
		void setMaxY(double);
		void setImgWidth(double);
		void setImgHeight(double);
		void setDirection(Direction);
		
		void updateValues();
		
	private:
		double xMin;
		double yMin;
		double xMax;
		double yMax;
		double imgWidth;
		double imgHeight;
		Direction currentDirection;
};
#endif
