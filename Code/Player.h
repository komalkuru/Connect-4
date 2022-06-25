#pragma once
#include <iostream>
using namespace std;

class Player {
  private:
    int players;

  public:
    Player();
    int getPlayers();
    int makeMove(char);
    char selectPlayer(int);
};