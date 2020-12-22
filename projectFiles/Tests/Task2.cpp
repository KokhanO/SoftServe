#include "gtest/gtest.h"
#include "Letter.h"

//----------------------------------Task2------------------------------------//
TEST(Letter, lessOrEqual) {
	Letter a(12.1f, 13.6f);
	Letter b(14.6f, 15.3f);
	EXPECT_TRUE(a <= b);
}
//----------------------------------Task2------------------------------------//
