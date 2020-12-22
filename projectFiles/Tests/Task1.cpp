#include "gtest/gtest.h"
#include "ChessBoard.h"

//----------------------------------Task1------------------------------------//


ChessBoard a(6, 8);
WhiteCell wc(' ');
BlackCell bc('*');

TEST(ChessBoard, getters) {
	EXPECT_EQ(6, a.getRows());
	EXPECT_EQ(8, a.getColumns());
}

TEST(Cell, getters) {
	EXPECT_EQ(' ', wc.getTexture());
	EXPECT_EQ('*', bc.getTexture());
}

TEST(ChessBoard, fillBoard) {
	a.fillBoard(wc, bc);
	EXPECT_EQ(48, a.board_.size());
	EXPECT_EQ(' ', a.board_[0]->getTexture());
	EXPECT_EQ('*', a.board_[1]->getTexture());
}
