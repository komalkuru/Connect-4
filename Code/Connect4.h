#pragma once
#include "Board.h"
#include "Player.h"

using namespace std;

class Connect4 {
  private:
    bool isGameOver;
    int input;

    void updatePlayerMove();
    void setInput(int value);

    Board board;
    Player players;


  public:
    Connect4();
    void execute();
};
