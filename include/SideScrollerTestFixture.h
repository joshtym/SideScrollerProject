#ifndef SIDESCROLLERTESTFIXTURE_H
#define SIDESCROLLERTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "ObjectDimensions.h"
#include "CollisionDetection.h"

/// Class that tests Collision Detection
/**
 * Class tests all 4 possibilities of collision from the collision
 * detection class. There are 4 sides to any obstacle. It tests collision
 * from the top, bottom, right, and left hand sides
**/
class SideScrollerTestFixture : public CppUnit::TestFixture
{
	public:
		/// Initialization of the Test Suite
		CPPUNIT_TEST_SUITE(SideScrollerTestFixture);
		
		/// All the CPPUNIT Tests
		CPPUNIT_TEST(testCollideFromLeftSide);
		CPPUNIT_TEST(testCollideFromRightSide);
		CPPUNIT_TEST(testCollideFromBottom);
		CPPUNIT_TEST(testCollideFromTop);
		
		/// End of Test Suite
		CPPUNIT_TEST_SUITE_END();
		
	public:
		/// SetUp and TearDown Fixture functions
		/**
		 * Initializes default values to both the test objects
		 * Mainly initializes the default values for imgWidth and
		 * height on both objects
		**/
		void setUp();
		void tearDown();
		
		/// Test Functions for the CPPUNIT tests
		void testCollideFromLeftSide();
		void testCollideFromRightSide();
		void testCollideFromBottom();
		void testCollideFromTop();
		
	private:
		/// Private data members used in the tests
		ObjectDimensions testObject1;
		ObjectDimensions testObject2;
		CollisionDetection cd;
};
#endif
