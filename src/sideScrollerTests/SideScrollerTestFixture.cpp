#include "SideScrollerTestFixture.h"

void SideScrollerTestFixture::setUp()
{
	// Initialize default imgWidth and imgHeight values
	testObject1.setImgHeight(20);
	testObject1.setImgWidth(50);
	testObject2.setImgHeight(5);
	testObject2.setImgWidth(10);
}

void SideScrollerTestFixture::tearDown()
{
}

void SideScrollerTestFixture::testCollideFromLeftSide()
{
	// Set testObject1 and testObject2 values such that testObject1
	// is colliding with testObject2 from the left side
	testObject1.setMinX(12);
	testObject1.setMinY(100);
	testObject1.updateValues();
	
	testObject2.setMinX(3);
	testObject2.setMinY(100);
	testObject2.updateValues();
	
	CPPUNIT_ASSERT(cd.checkForCollision(testObject1, testObject2));
}

void SideScrollerTestFixture::testCollideFromRightSide()
{
	// Set testObject1 and testObject2 values such that testObject1
	// is colliding with testObject2 from the right side
	testObject1.setMinX(12);
	testObject1.setMinY(100);
	testObject1.updateValues();
	
	testObject2.setMinX(4);
	testObject2.setMinY(100);
	testObject2.updateValues();
	
	CPPUNIT_ASSERT(cd.checkForCollision(testObject1, testObject2));
}

void SideScrollerTestFixture::testCollideFromBottom()
{
	// Set testObject1 and testObject2 values such that testObject1
	// is colliding with testObject2 from the top
	testObject1.setMinX(10);
	testObject1.setMinY(30);
	testObject1.updateValues();
	
	testObject2.setMinX(10);
	testObject2.setMinY(28);
	testObject2.updateValues();
	
	CPPUNIT_ASSERT(cd.checkForCollision(testObject1, testObject2));
}

void SideScrollerTestFixture::testCollideFromTop()
{
	// Set testObject1 and testObject2 values such that testObject1
	// is colliding with testObject2 from the bottom
	testObject1.setMinX(10);
	testObject1.setMinY(10);
	testObject1.updateValues();
	
	testObject2.setMinX(10);
	testObject2.setMinY(25);
	testObject2.updateValues();
	
	CPPUNIT_ASSERT(cd.checkForCollision(testObject1, testObject2));
}
