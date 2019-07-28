#ifndef FACTORYSPACE_H_INCLUDED
#define FACTORYSPACE_H_INCLUDED
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
namespace factorySpace ///Creation of a namespace
{
    ///Type definations of the pointer
    typedef int* t_1DArray;
    typedef int** t_2DArray;

    ///Enumerations for return codes
    enum enumReturn_Codes
    {
        SUCCESS,
        INVALID_INPUT,
        INVALID_ARGS,
        EXIT
    };

    ///Enumeration of the features
    enum enumFeatures
    {
        PLAYER,
        SPACE,
        FACRORY,
        PARTS
    };

    ///Character of the features of the game
    const char CH_FEATURES[]={'P','~','#','@'};

    ///Structure of cordinates
    struct struLocation
    {
        int row=-1;
        int col=-1;
    };

    ///Structure of the game
    struct struGameWorld
    {
        struLocation Player;
        int row=-1;
        int col=-1;
        t_2DArray arrWorld;
    };

  ///function of the game
  void validateArgs(int argc,char** argv);
  void convertToInt(string strNumber);
  int genRandom(int intMin,int intMax);
  struGameWorld makeWorld(int intRow,int intCol,int intParts);
  void displayWorld(const struGameWorld& recworld);
  bool isInWorld(struGameWorld& recworld);
  void movePlayer(struGameWorld& recworld);
  void deAllocateMemory(struGameWorld& recworld);





}


#endif // FACTORYSPACE_H_INCLUDED
