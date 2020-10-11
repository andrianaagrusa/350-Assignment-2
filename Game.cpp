#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <time.h>
#include "Game.h"

// which mode they want to run, then run that mode
void Game::userMode(char **&board, int &boardHeight, int &boardLength)
{
  cout << "Select which mode to run: Classic, Doughnut, or Mirror" << endl;
  string userChoiceMode;
  cin >> userChoiceMode;

  if (userChoiceMode == "Classic")
  {
    ClassicMode classicMode;
    classicMode.createNextGeneration(board, boardHeight, boardLength);
  }

  else if (userChoiceMode == "Doughnut")
  {
    DoughnutMode doughnutMode;
    doughnutMode.createNextGeneration(board, boardHeight, boardLength);
  }

  else if (userChoiceMode == "Mirror")
  {
    MirrorMode mirrorMode;
    mirrorMode.createNextGeneration(board, boardHeight, boardLength);
  }
}

// generate a board based on a given file
void Game::makeMapFileBoard()
{
  ifstream file;
  string userInputFile;
  cout << "Enter the file you would like to open: " << endl;
  cin >> userInputFile;
  file.open("userInputFile");
  int lineCount = 0;
  string line = "";

  // set first two lines of the file as the array dimensions
  while (getline(file, line))
  {
    if (lineCount == 0)
      boardHeight = atoi(line.c_str());
    else if (lineCount == 1)
      boardLength = atoi(line.c_str());
    else
      break;
    lineCount++;
  }

  lineCount = 0;

// makes the array
  char** mapFileBoard = new char*[boardHeight];

  for (int i = 0; i < boardHeight; i++)
  {
    mapFileBoard[i] = new char[boardLength];
  }

// initialize
  for (int i = 0; i < boardHeight; i++)
  {
    for (int j = 0; j < boardLength; j++)
    {
      mapFileBoard[i][j] = ' ';
    }
  }

// start from the beginning of the line
  file.seekg(0, file.beg);

  int thisRow = 0;
  while (getline(file, line))
  {
    // fill the array
    if (lineCount == 0) {}
    else if (lineCount == 1){}
    else
    {
      for (int i = 0; i < boardHeight; i++)
      {
        char thisChar = line[i];
        mapFileBoard[thisRow][i] = thisChar;
      }
      thisRow++;
    }
    lineCount++;
  }
  file.close();
  userMode(mapFileBoard, boardHeight, boardLength);
}

//generates a random generation board
void Game::makeRandomBoard(int& boardHeight, int &boardLength)
{
  cout << "Enter a number for the height: " << endl;
  cin >> boardHeight;

  cout << "Enter a number for the length: " << endl;
  cin >> boardLength;

  double decimalValue = 0.0;
  cout << "Enter a decimal between 0 and 1: " << endl;
  cin >> decimalValue;
  char** randomBoard = new char*[boardHeight];

    for (int i = 0; i < boardHeight; ++i)
      {
      	randomBoard[i] = new char[boardLength];
      }
    for (int i = 0; i < boardHeight; i++)
    {
  		for (int j = 0; j < boardLength; j++)
      {
  			randomBoard[i][j] = '-';
  		}
    }

  // calulate how many X based on the random decimal value
  int numofX = round((boardHeight * boardLength) * decimalValue);

  // fills the array
  for (int i = 0; i < boardHeight; i++)
  {
    for (int j = 0; j < boardLength; j++)
    {
      if (numofX > 0) {
        randomBoard[i][j] = 'X';
        numofX--;
      }
      else
      {
        randomBoard[i][j] = '-';
      }
    }
  }

// shuffles the array
  for (int i = 0; i < boardHeight; i++)
  {
    int randomVal = i + (rand() % (boardHeight-i+1));
    for (int j = 0; j < boardLength; j++)
    {
      int tempVal = randomBoard[i][j];
      randomBoard[i][j] = randomBoard[randomVal][j];
      randomBoard[randomVal][j] = tempVal;
    }
  }
  userMode(randomBoard, boardHeight, boardLength);

}

// user chooses how to generate the initial generation board
void Game::promptUser()
{
  cout << "Type RANDOM for a random assignment or MAP to open a map file." << endl;
  string userChoice1 = "";
  cin >> userChoice1;

  if (userChoice1 == "MAP")
  {
    makeMapFileBoard();
  }
  else if (userChoice1 == "RANDOM")
  {
    makeRandomBoard(boardHeight, boardLength);
  }
}
