/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurn_X_To_O)
{
	Piece retval;
	TicTacToeBoard T = TicTacToeBoard();
	retval = T.toggleTurn();
	ASSERT_EQ(retval, O);
}

TEST(TicTacToeBoardTest, toggleTurn_O_To_X)
{
	Piece retval;
	TicTacToeBoard T = TicTacToeBoard();
	retval = T.toggleTurn();
	retval = T.toggleTurn();
	ASSERT_EQ(retval, X);
}
TEST(TicTacToeBoardTest, getWinner_Blank_Board){
	TicTacToeBoard T = TicTacToeBoard();
	Piece retval = T.getWinner(0, 0);
	ASSERT_EQ(retval, Invalid);
}
TEST(TicTacToeBoardTest, placePiece_Blank_Board){
	TicTacToeBoard T = TicTacToeBoard();
	Piece retval = T.placePiece(0, 0);
	ASSERT_EQ(retval, X);
}
TEST(TicTacToeBoard, placePiece_Already_Placed){
	TicTacToeBoard T = TicTacToeBoard();
	T.placePiece(0,0);
	T.placePiece(0,0);
	ASSERT_EQ(T.getPiece(0,0), X);
}
TEST(TicTacToeBoard, getWinner_X_Wins_Row){
	TicTacToeBoard T = TicTacToeBoard();
	T.placePiece(0,0);
	T.placePiece(2,2);
	T.placePiece(0, 1);
	T.placePiece(2, 0);
	T.placePiece(0, 2);
	Piece retval = T.winningPiece();
	ASSERT_EQ(retval, X);
}

TEST(TicTacToeBoard, getWinner_O_Wins_Row){
	TicTacToeBoard T = TicTacToeBoard();
	T.placePiece(0,0);
	T.placePiece(2,2);
	T.placePiece(1, 1);
	T.placePiece(2, 0);
	T.placePiece(0, 2);
	T.placePiece(2, 1);
	Piece retval = T.winningPiece();
	ASSERT_EQ(retval, O);
}

TEST(TicTacToeBoard, placePiece_OOB){
	TicTacToeBoard T = TicTacToeBoard();
	Piece retval = T.placePiece(4, 4);
	ASSERT_EQ(retval, Invalid);
}

TEST(TicTacToeBoard, PlacePiece_After_Game_Over){
	TicTacToeBoard T = TicTacToeBoard();
	T.placePiece(0,0);
	T.placePiece(2,2);
	T.placePiece(1, 1);
	T.placePiece(2, 0);
	T.placePiece(0, 2);
	T.placePiece(2, 1);
	Piece retval = T.placePiece(1, 2);
	ASSERT_EQ(retval, X);
}

TEST(TicTacToeBoard, getPiece_OOB){
	TicTacToeBoard T = TicTacToeBoard();
	Piece retval = T.getPiece(4, 4);
	ASSERT_EQ(retval, Invalid);
}


TEST(TicTacToeBoard, GetWinner_X_Wins_Col){
	TicTacToeBoard T = TicTacToeBoard();
	T.placePiece(0,0);
	T.placePiece(0,1);
	T.placePiece(1,0);
	T.placePiece(1,1);
	T.placePiece(2,0);
	Piece retval = T.winningPiece();
	ASSERT_EQ(retval, X);
}


TEST(TicTacToeBoard, GetWinner_X_Wins_Diag){
	TicTacToeBoard T = TicTacToeBoard();
	T.placePiece(0,0);
	T.placePiece(0,1);
	T.placePiece(1,1);
	T.placePiece(1,2);
	T.placePiece(2,2);
	Piece retval = T.winningPiece();
	ASSERT_EQ(retval, X);
}

TEST(TicTacToeBoard, GetWinner_X_Wins_Reverse_Diag){
	TicTacToeBoard T = TicTacToeBoard();
	T.placePiece(0,2);
	T.placePiece(0,1);
	T.placePiece(1,1);
	T.placePiece(1,2);
	T.placePiece(2,0);
	Piece retval = T.winningPiece();
	ASSERT_EQ(retval, X);
}

TEST(TicTacToeBoard, GetWinner_Draw){
	TicTacToeBoard T = TicTacToeBoard();
	T.placePiece(0,0);
	T.placePiece(0,1);
	T.placePiece(0,2);
	T.placePiece(1,0);
	T.placePiece(1,2);
	T.placePiece(1,1);
	T.placePiece(2,0);
	T.placePiece(2,2);
	T.placePiece(2,1);
	Piece retval = T.winningPiece();
	ASSERT_EQ(retval, Draw);
}