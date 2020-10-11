#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class MirrorMode
{
public:
  MirrorMode(){}
  ~MirrorMode(){}

  void createNextGeneration(char **&board, int &boardHeight, int &boardLength);
  void outputChoices();

  int boardHeightheight;
  int boardLength;
  char **board;
  int count;
  char userOutputChoice;

};
