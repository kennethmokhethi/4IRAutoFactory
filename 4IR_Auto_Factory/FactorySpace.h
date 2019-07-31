#ifndef FACTORYSPACE_H_INCLUDED
#define FACTORYSPACE_H_INCLUDED
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <cassert>

using namespace std;
namespace factorySpace ///Creation of a namespace
{
    ///Type definations of the pointerS
    typedef int* t_1DArray;
    typedef int** t_2DArray;


    ///Enumerations for return codes
    enum enumReturn_Codes
    {
        SUCCESS,
        INVALID_INPUT,
        ERROR_CONV,
        INVALID_ARGC,
        WON,
        LOST,
        EXIT
    };

    ///Enumeration of the features
    enum enumFeatures
    {
        PLAYER,
        SPACE,
        FACTORY,
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
        int parts=-1;
        int g_score=10;
        int g_part=0;
        t_2DArray arrWorld;
    };

  ///function of the game
  void validateArgs(int argc,char** argv);
  int convertToInt(string strNumber);
  int genRandom(int intMin,int intMax);
  struGameWorld makeWorld(int intRow,int intCol,int intParts);
  void displayWorld(struGameWorld& recworld);
  bool isInWorld(struGameWorld& recworld);
  void movePlayer(struGameWorld& recworld,char chInput);
  void outcome(struGameWorld& recworld);
  void deAllocateMemory(struGameWorld& recworld);





}


#endif // FACTORYSPACE_H_INCLUDED
