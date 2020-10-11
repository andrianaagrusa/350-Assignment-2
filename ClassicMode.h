#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ClassicMode
{
public:

  ClassicMode(){}
  ~ClassicMode(){}

  void createNextGeneration(char **&board, int &boardHeight, int &boardLength);
  void outputChoices();

  int boardHeightheight;
  int boardLength;
  char **board;
  int count;
  char userOutputChoice;

};
