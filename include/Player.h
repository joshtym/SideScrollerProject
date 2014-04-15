#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/keyboard.h>
#include "InputManagement.h"
#include "SpriteSheet.h"
#include "ObjectDimensions.h"
/// Class to initialize player object for GameScreen
/**
 * Class Player creates a player object.
 * It populates a ObjectDimensions object for use with collision detection.
 * Holds functions to move the player around the screen including jumping, left, right and gravity.
 * Sets the bottom of the stage for ground movement and detects platforms allowing interaction.
 * It also holds the sprite object for image rendring the toon.
*/ 
class Player 
{	
	public:
		Player();
		~Player();
		void loadPlayer();
		void unloadPlayer();
		
		/// Updates the Players position
		/** The update triggers all the functions that recalculate the player's next rendered position of the player.
		 * This does not draw the player, only sets the current x and y values.
		 \param ALLEGRO_EVENT The event that is passed into move player for keyboard input
		 \param InputManagement gets current key state for keyboard
		*/
		void update(ALLEGRO_EVENT, InputManagement);
		
		///Moves player by keyboard input
		/**
		 * The update triggers all the functions that recalculate the player's next rendered position of the player.
		 * This does not draw the player, only sets the current x and y values.
		 \param ALLEGRO_EVENT This is the keyboard event used to calculate the players next position
		**/
		void movePlayer(ALLEGRO_EVENT);
		
		///Draws Player to Allegro display
		/**
		 * Updates the display with the new image for the player
		 \param ALLEGRO_DISPLAY* Takes the currently used display
		**/
		void draw(ALLEGRO_DISPLAY*);
		
		///Adds gravity to player
		/**
		 * Applies gravity to the character every tick by incrementing the y value of the
		 * character
		**/
		void gravityTick();
		
		///Loops the jump tick for smooth jump animation
		/**
		 * Loops the jump animation over 5 ticks to make smooth jumps possible
		**/
		void jumpTick();
		
		///Sets y value of character, includes error catching
		/**
		 * Sets the player to the new y value safely. This is used to ensure you the
		 * player doesn't break through the floor and stops the player from jumping off the floor.
		 \param ALLEGRO_DISPLAY* Takes the currently used display
		**/
		void setY(double);
		
		///moves player back to allowed positions
		/**
		 * Sets the characters last known good x position to prevent the toon from jumping through walls.
		**/
		void setXStatic();
		
		///Sets variable to allow platform jumps
		/**
		 * Sets a boolean to detect if you are on a platform. used for jumping mainly.
		**/
		void setIsOnPlatform(bool);
		
		///sets floor level
		/**
		 * Sets the floor level to help jumping logic.
		 \param double sets the floor level for player
		**/
		void setFloorLevel(double);
		
		///increments Momentium
		/**
		 * Add momentum to the x axis allowing the player to run fast and slow over ticks. More means longer carrying
		 \param int Momentium value 
		**/
		void addMomentium(int);
		
		///Momentum allows player x movment when not pressing key. always moves towards 0
		/**
		 * Momentium is calculated by the momentium variable.
		 * if positive multiplies increases the x value by the distance you want to move then decremented,
		 * else if negitive multiplies decreases the x value by the distance you want to move then incremented
		 * else if 0 does nothing
		**/
		void applyMomentium();
		
		///gets last known good position of player
		/**
		 * getLastXPosition gets last known good position and resets the player before draw so player does not
		 * move through objects
		**/
		int getLastXPosition();
		
		///Sets the stage speed
		/**
		 * sets speed that stage moves
		 \param double speed to move stage
		**/
		double setStageSpeed(double);
		
		///Gets current dimemtion object
		/**
		 * gets current dimension object for comparison 
		 \return ObjectDimensions&
		**/
		ObjectDimensions& getCurrentDimensions();
		
	private:
		///Player Image
		ALLEGRO_BITMAP *playerBitmap;
		///Animation for player movement
		Animation playerAnimation;
		SpriteSheet ssAnimation;
		///Players dimetions on screen
		ObjectDimensions playerDimensions;
		///movment variables
		int jumpCounter;
		int lastXPosition;
		int otherTick;
		int tick;
		int moveSpeed;
		int jCount;
		int momentium;
		double floor;
		double stageFloor;
		double stageSpeed = 0;
		bool onPlatform;
		bool jump;
		
};
#endif
 
