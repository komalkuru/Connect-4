#include "Board.h"
#include <iostream>
using namespace std;

Board :: Board() {
  maximumRow = 6, maximumColumn = 7;
  createBoard();
  rowNumber = 0;
  printBoard();
  noOfConnections = 0;
  filledColumns = 0;
  gameOver = false;
}

int Board :: getRowNumber() {
  return rowNumber;
}

int Board :: getMaximumColumn() {
  return maximumColumn;
}

void Board :: createBoard() {
  makeboard = new char*[maximumRow];
  for(int i = 0; i < maximumRow; i++) {
    makeboard[i] = new char[maximumColumn];
  }

  for( int i = 0; i < maximumRow; i++ ) {
    for( int j = 0; j < maximumColumn; j++ ) {   
      makeboard[i][j] = ' ';
    }
  }
} 

void Board :: printColumnNumbers() {
    for(int i = 0; i < maximumColumn; i++) {
        cout << "|" << i+1;    
    }
    cout << "|" << endl;
    cout << endl<<endl;
}

void Board :: printBoard() {
    printColumnNumbers();
    for( int i = 0; i < maximumRow; i++ ) {
      for( int j = 0; j < maximumColumn; j++ ) {      
        cout << "|";
        cout<<makeboard[i][j];
      }
      cout<<"|"<<endl;
    }
    cout<<endl;
}

int Board:: placeMarker(int input, char playerCharacter) {  
  
  if( (makeboard[0][input-1] != ' ') && (input != -1) ) {
    return -1;
  }
  
  int row;
  for(row = maximumRow-1; row >= 0; row--) {
    if(makeboard[row][input-1] == ' ') {
      makeboard[row][input-1] = playerCharacter;
      break;
    }
  }
  
  return row;
}

void Board :: playGame(int input, char playerCharacter) {
  rowNumber = placeMarker(input,playerCharacter); 
  if(rowNumber == -1) {
    return;
  }
  
  printBoard();  
  gameOver = winCondition(rowNumber,input,playerCharacter);
}


int Board :: horizontalWin (int rowNumber, int input, char playerCharacter) {
  noOfConnections = 0;
  
  for(int col = input-1; col < maximumColumn; col++) {
    if(makeboard[rowNumber][col] == playerCharacter) {
      noOfConnections++;
    } else { 
      break; 
      }
  }

  for(int col = input-2; col >= 0; col--) {
    if(makeboard[rowNumber][col] == playerCharacter) {
      noOfConnections++;
      } else { 
        break; 
      }
  }

  return noOfConnections;
}


int Board :: verticalWin(int rowNumber, int input, char playerCharacter) {
  noOfConnections = 0;
  
  for(int row = rowNumber; row < maximumRow; row++) {
    if(makeboard[row][input-1] == playerCharacter) {
      noOfConnections++;
    } else { 
      break; 
    }
  }
  return noOfConnections;
} 

int Board :: diagonalWin(int rowNumber,int input, int playerCharacter) {
  noOfConnections = 0; 
  int col = input - 1;

  for(int row = rowNumber; row >= 0; row-- ) {
    if(makeboard[row][col] == playerCharacter) {
      noOfConnections++;
      ++col;
      
    } else { break; }
  }
   

  col = input - 2;
  for(int row = rowNumber+1; row < maximumRow; row++ ) {   
    if(makeboard[row][col] == playerCharacter) {
      noOfConnections++;
      --col;
    } else { break; }
  }
  

  if(noOfConnections >= 4)  {
    return noOfConnections;
  } 

  noOfConnections = 0;

  col = input - 1;
  for(int row = rowNumber; row >= 0; row-- ) {
    if(makeboard[row][col] == playerCharacter) {
      noOfConnections++;
      --col;
    } else { break; }
  }

  col = input;

  for(int row = rowNumber+1; row < maximumRow; row++ ) {
    if(makeboard[row][col] == playerCharacter) {
      noOfConnections++;
      ++col;  
    } else { break; }
  }
    
  return noOfConnections;
}

int Board :: drawGame() {
  ++filledColumns;
  return filledColumns;
}

bool Board :: winCondition(int rowNumber, int input,char playerCharacter) {  
  string playerColor;
  if(playerCharacter == 'R') {
    playerColor = "Red";
  }

  if(playerCharacter == 'Y') {
    playerColor = "Yellow";
  }

  if( (drawGame() >= maximumRow * maximumColumn ) && (gameOver!=true)) {
     cout<<"\n\nDraw Game!!\n\n";
    gameOver = true;
  }
  
  if(horizontalWin(rowNumber,input,playerCharacter) >= 4 && (gameOver!=true)) {
    cout<<"\n\n "<< playerColor << " player win!!!\n\n";
    gameOver = true;
  }

  if(verticalWin(rowNumber,input,playerCharacter) >= 4 && (gameOver!=true)) {
    cout<<"\n\n "<< playerColor << " player win!!!\n\n";
    gameOver = true;
  } 
  
  if(diagonalWin(rowNumber,input,playerCharacter) >= 4 && (gameOver!=true)) {
    cout<<"\n\n "<< playerColor << " player win!!!\n\n";
    gameOver = true;
  } 
  
  return gameOver;
}

bool Board :: checkGameOver() {
  return gameOver;
}

Board :: ~Board() {
  delete[] makeboard;
}