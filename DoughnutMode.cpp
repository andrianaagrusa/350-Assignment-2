#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "DoughnutMode.h"
using namespace std;

void DoughnutMode::outputChoices()
{
  cout << "Enter the number for the option you would like to do: " << endl;
  cout << "1. Have a brief pause between generations" << endl;
  cout << "2. Press the 'Enter' key to create a new generation." << endl;
  cout << "3. Output all new generations to a file." << endl;
  userOutputChoice;
  cin >> userOutputChoice;
}

// runs doughbut mode
void DoughnutMode::createNextGeneration(char **&board, int &boardHeight, int &boardLength) //see whats in that spot
{
  // makes the new generation array
  char** newGeneration = new char*[boardHeight];
  for (int i = 0; i < boardHeight; ++i)
  {
    newGeneration[i] = new char[boardLength];
  }
  int genNumber = 0;
  bool stabilized = false;

  while (stabilized == false)
  {
    for (int i = 0; i < boardHeight; i++)
    {
      for (int j = 0; j < boardLength; j++)
      {
        count = 0;

        if (i == 0 && j == 0) // top left corner
        {
          if (board[i][j+1] == 'X')
            count++;
          if (board[i+1][j+1] == 'X')
            count++;
          if (board[i+1][j] == 'X')
            count++;
          if (board[i+1][boardLength-1] == 'X')
            count++;
          if (board[i][boardLength-1] == 'X')
            count++;
          if (board[boardHeight-1][boardLength-1] == 'X')
            count++;
          if (board[boardHeight-1][j] == 'X')
            count++;
          if (board[boardHeight-1][j+1] == 'X')
            count++;
        }


        else if (i == 0 && j == (boardLength - 1)) // top right corner
        {
          if (board[i][j-1] == 'X')
            count++;
          if (board[boardHeight-1][j-1] == 'X')
            count++;
          if (board[boardHeight-1][j-1] == 'X')
            count++;
          if (board[boardHeight-1][j] == 'X')
            count++;
          if (board[boardHeight-1][0] == 'X')
            count++;
          if (board[i][0] == 'X')
            count++;
          if (board[i+1][0] == 'X')
            count++;
          if (board[i+1][j] == 'X')
            count++;
        }

        else if (i == (boardHeight - 1) && j == (boardLength - 1)) // bottom right corner
        {
          if (board[i][j-1] == 'X')
            count++;
          if (board[i-1][j-1])
            count++;
          if (board[i-1][j] == 'X')
            count++;
          if (board[i-1][0] == 'X')
            count++;
          if (board[i][0] == 'X')
            count++;
          if (board[0][0] == 'X')
            count++;
          if (board[0][j] == 'X')
            count++;
          if (board[0][j-1] == 'X')
            count++;
        }

        else if (i == (boardHeight-1) && j ==0) // bottom left corner
        {
          if (board[i][boardLength-1] == 'X')
            count++;
          if (board[i-1][boardLength-1] == 'X')
            count++;
          if (board[i-1][j] == 'X')
            count++;
          if (board[i-1][j+1] == 'X')
            count++;
          if (board[i][j+1] == 'X')
            count++;
          if (board[0][j+1] == 'X')
            count++;
          if (board[0][0] == 'X')
            count++;
          if (board[0][boardLength-1] == 'X')
            count++;
        }

        else
        {
          if (board[i-1][j-1] == 'X')
            count++;
          if (board[i-1][j] == 'X')
            count++;
          if (board[i-1][j+1] == 'X')
            count++;
          if (board[i][j+1] == 'X')
            count++;
          if (board[i+1][j+1] == 'X')
            count++;
          if (board[i+1][j] == 'X')
            count++;
          if (board[i+1][j-1] == 'X')
            count++;
          if (board[i][j-1] == 'X')
            count++;
        }
 // gathers how many neighbors and determines the next generation cell
        if (count <= 1)
          newGeneration[i][j] == '-';

        if (count == 2)
        {
          if (board[i][j] == 'X')
            newGeneration[i][j] == 'X';
          else
            newGeneration[i][j] == '-';
        }

        if (count == 3)
          newGeneration[i][j] == 'X';

        if (count >=4)
          newGeneration[i][j] == '-';
      }
    }

// check if it's stabilized
    int sameChar = 0;
    for (int i = 0; i < boardHeight; i++)
    {
      for (int j = 0; j < boardLength; j++)
      {
        if (newGeneration[i][j] == board[i][j])
        {
          sameChar++;
        }
        else
        {
          stabilized = false;
        }
      }
    }

    if (sameChar == (boardHeight*boardLength))
    {
      stabilized == true;
      cout << "Generations have stabilized." << endl;
    }

    if (stabilized == false)
    {
      cout << "Generation " << genNumber;
    }
    genNumber++;

    outputChoices();

    if (userOutputChoice == '1')
    {
      sleep(1);
      cout << "Generation #" << genNumber<< endl;
      for (int i = 0; i < boardHeight; i++)
      {
        for (int j = 0; j < boardLength; j++)
        {
          cout << newGeneration[i][j];
        }
        cout << " " << endl;
      }
    }

    if (userOutputChoice = '2')
    {
      cout << "Hit Enter to continue." << endl;
      if (cin.get() == true)
      {
        cout << "Generation #" << genNumber<< endl;
        for (int i = 0; i < boardHeight; i++)
        {
          for (int j = 0; j < boardLength; j++)
          {
            cout << newGeneration[i][j];
          }
          cout << " " << endl;
        }
      }
    }

      if (userOutputChoice == '3')
      {
        cout << "Enter the file to output to: " << endl;
        ofstream outputFile;
        string outputFileName;
        cin >> outputFileName;
        outputFile.open("outputFileName");
        cout << "Generation #" << genNumber<< endl;
        for (int i = 0; i < boardHeight; i++)
        {
          for (int j = 0; j < boardLength; j++)
          {
            outputFile << newGeneration[i][j];
          }
          outputFile << " " << endl;
        }

      }
// sets the new generation as the current generation
    for (int i = 0; i < boardHeight; i++)
    {
      for (int j = 0; j < boardLength; j++)
      {
        board[i][j] = newGeneration[i][j];
      }
    }
  }
}
