#ifndef OBJECTDIMENSIONS_H
#define OBJECTDIMENSIONS_H

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
		
		void setMinX(double);
		void setMinY(double);
		void setMaxX(double);
		void setMaxY(double);
		void setImgWidth(double);
		void setImgHeight(double);
		
		void updateValues();
		
	private:
		double xMin;
		double yMin;
		double xMax;
		double yMax;
		double imgWidth;
		double imgHeight;
};
#endif
