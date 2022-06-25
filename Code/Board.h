#pragma once
#include <bits/stdc++.h>
using namespace std;

class Board {
    char** makeboard;   

    int maximumRow;
    int maximumColumn;
    int noOfConnections;
    int rowNumber;
    int filledColumns;

    bool gameOver;
    void printColumnNumbers();
    void printBoard();
    void createBoard();

    int placeMarker(int , char);
    int horizontalWin(int,int,char);
    int verticalWin(int,int,char);
    int diagonalWin(int,int, int);
    int drawGame();

    bool winCondition(int,int,char);
    
  public:
    Board();
    ~Board();

    void playGame(int,char);

    int getMaximumColumn();
    int getRowNumber();

    bool checkGameOver();
   
};