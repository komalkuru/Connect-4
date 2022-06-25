#include "Player.h"
#include <iostream>
using namespace std;

Player :: Player() {
  players = 2;
}

int Player :: getPlayers() {
  return players;
}

char Player :: selectPlayer(int playerIndex) {
  char character;
  if(playerIndex == 0) {
    character = 'R';
  } else {
    character = 'Y';
  }
  return character;
} 

int Player :: makeMove(char playerCharacter) {
  int column;
  string playerColor;
  if(playerCharacter == 'R') {
    playerColor = "Red";
  }

  if(playerCharacter == 'Y') {
    playerColor = "Yellow";
  }
  
  std::cout<<"\n\nEnter the column number to push " << playerColor << " Player : ";
  std::cin>>column;
  return column;
}
