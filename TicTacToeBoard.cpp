#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  moveCount = 0;
  winner = Blank;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn==X){
    turn=O;
  }else{
    turn=X;
  }
  moveCount++;
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(gameOver){
    return turn;
  }
  if(row < BOARDSIZE){
    if(column < BOARDSIZE){
      if(board[row][column] == Blank){
        board[row][column] = turn;
        Piece win = getWinner(row, column);
        if(win == X){
          winner = X;
          gameOver = true;
        }if(win == O){
          winner = O;
          gameOver = true;
        }if(win == Draw){
          winner = Draw;
          gameOver = true;
        }
        toggleTurn();
        return board[row][column];
      }else{
        return board[row][column];
      }
    }
  }
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row < BOARDSIZE){
    if(column < BOARDSIZE){
      return board[row][column];
    }
  }
  return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner(int row, int column)
{
  
  //check cols
  for(int i = 0; i <BOARDSIZE; i++){
    if(board[row][i] != turn)
        break;
    if(i == BOARDSIZE-1){
        return turn;
    }
  }

  //check row
  for(int i = 0; i < BOARDSIZE; i++){
    if(board[i][column] != turn)
        break;
    if(i == BOARDSIZE-1){
        return turn;
    }
  }
  if(row == column){
        //we're on a diagonal
    for(int i = 0; i < BOARDSIZE; i++){
        if(board[i][i] != turn)
            break;
        if(i == BOARDSIZE-1){
            return turn;
        }
    }
  }
  if(row + column == BOARDSIZE - 1){
    for(int i = 0; i < BOARDSIZE; i++){
        if(board[i][(BOARDSIZE-1)-i] != turn)
            break;
        if(i == BOARDSIZE-1){
            return turn;
        }
    }
    }
    if(moveCount == (pow(BOARDSIZE, 2) - 1)){
            return Draw;
    }
    return Invalid;
}

Piece TicTacToeBoard::winningPiece(){
  return winner;
}