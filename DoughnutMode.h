#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class DoughnutMode
{
public:

  DoughnutMode(){}
  ~DoughnutMode(){}

  void createNextGeneration(char **&board, int &boardHeight, int &boardLength);
  void outputChoices();

int boardHeightheight;
int boardLength;
char board;
int count;
char userOutputChoice;


};
