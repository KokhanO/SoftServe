#include "gtest/gtest.h"
#include "Triangle.h"

Triangle a("Triangle1", 3.0f, 4.0f, 5.0f);
//----------------------------------Task3------------------------------------//
TEST(Triangle, getters) {
	EXPECT_EQ("Triangle1", a.getName());
	EXPECT_EQ(6.0f, a.getSquare());
	EXPECT_EQ(12.0f, a.getPerimeter());
}

TEST(Triangle, triangleExistence) {
	EXPECT_TRUE(a.triangleExistence(2.0f, 2.0f, 2.0f));
	EXPECT_TRUE(a.triangleExistence(12.0f, 13.0f, 15.0f));
	EXPECT_FALSE(a.triangleExistence(1.0f, 2.0f, 3.0f));
	EXPECT_FALSE(a.triangleExistence(1.0f, 3.2f, 15.0f));
}

