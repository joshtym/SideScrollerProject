#ifndef OBJECTDIMENSIONS_H
#define OBJECTDIMENSIONS_H

/// Enum to handle direction of object
enum Direction {DOWN, LEFT, RIGHT, UP};

/// Class to handle all ObjectDimensions
/**
 * Assigns what is essentially a box around each object that
 * uses this. Each object is assigned a minimum x and y value as well
 * as a maximum x and y value as well as image height and width. Note
 * that with allegro, minX and minY are the starting points of every
 * image. Containers both setters and getters as well as an updater
**/
class ObjectDimensions
{	
	public:
		/// Constructor for ObjectDimensions
		ObjectDimensions();
		
		/// Destructor for ObjectDimensions
		~ObjectDimensions();
		
		/// Getter functions for the object dimensions
		/**
		 * Get minimum x value
		**/
		double getMinX();
		
		/**
		 * Get minimum y value
		**/
		double getMinY();
		
		/**
		 * Get maximum x value
		**/
		double getMaxX();
		
		/**
		 * Get maximum y value
		**/
		double getMaxY();
		
		/**
		 * Get image/object width
		**/
		double getImgWidth();
		
		/**
		 * Get image/object height
		**/
		double getImgHeight();
		
		/**
		 * Get current direction of object
		**/
		Direction getCurrentDirection();
		
		/// Setter functions for the object dimensions
		/**
		 * Set minimum x value
		**/
		void setMinX(double);
		
		/**
		 * Set minimum y value
		**/
		void setMinY(double);
		
		/**
		 * Set maximum x value
		**/
		void setMaxX(double);
		
		/**
		 * Set maximum y value
		**/
		void setMaxY(double);
		
		/**
		 * Set image/object width
		**/
		void setImgWidth(double);
		
		/**
		 * Set image/object height
		**/
		void setImgHeight(double);
		
		/**
		 * Set current direction object
		**/
		void setDirection(Direction);
		
		/**
		 * Update all the values accordingly. Very useful if the
		 * drawing point, IE, minX, is changed. Allows us to update
		 * so the consistency remains intact
		**/
		void updateValues();
		
	private:
		/// Private data members
		double xMin;
		double yMin;
		double xMax;
		double yMax;
		double imgWidth;
		double imgHeight;
		Direction currentDirection;
};
#endif
