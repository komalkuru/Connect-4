#include "Connect4.h"
#include <bits/stdc++.h>
using namespace std;


Connect4 :: Connect4(){
  isGameOver = false;
}

void Connect4 :: updatePlayerMove() {
  int playerIndex = 0;
  int totalPlayers = players.getPlayers();
  int col = board.getMaximumColumn();
  
  while(isGameOver == false) {
    char playerCharacters = players.selectPlayer(playerIndex);
    int playedMove = players.makeMove(playerCharacters);
    
    if(playedMove == 0 || playedMove > col) {
      cout<<"\n\nYou made a wrong move!!\n\n";
      continue;
    } 

    board.playGame(playedMove,playerCharacters);    

    if(board.getRowNumber() == -1) {
      cout<<"\n\nThe column is filled!! Please change the column number!\n\n";
      continue;
    }
    
    if(board.checkGameOver() == true) {
      isGameOver = true;
    }
    
    playerIndex = (playerIndex + 1) % totalPlayers;
  }
}

void Connect4 :: execute() {
  while(!isGameOver) {
      updatePlayerMove();
    } 
}
