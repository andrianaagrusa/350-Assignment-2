#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"
using namespace std;

class Game
{
public:
  Game(){}
  ~Game(){}

  void makeMapFileBoard();
  void makeRandomBoard(int& boardHeight, int &boardLength);
  void promptUser();
  void userMode(char **&board, int &boardHeight, int &boardLength);

  string userChoice1;
  char** randomBoard;
  char** mapFileBoard;
  int boardHeight;
  int boardLength;
  char userOutputChoice;
  bool stabilized;
  int genNumber;
};
