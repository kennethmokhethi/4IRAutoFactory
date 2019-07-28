#include "FactorySpace.h"

using namespace std;
namespace factorySpace ///Implmementation of the factory namespace
{
    ///Validating to ensure that the command line arguments provided are 4
    void validateArgs(int argc,char** argv)
    {
        if(argc!=4)
        {
            cerr<<"Incorrect number of arguments for"<<argv[0]<<endl;
            exit(enumReturn_Codes::INVALID_ARGC);
        }
    }

   ///Implementation of function that convert strings to number
   int convertToInt(string strNumber)
   {
       stringstream convStr;
       convStr<<strNumber;
       int intNumber=0;
       convStr>>intNumber;
       if(convStr.fail())
       {
           cerr<<"Unable to convert to int"<<endl;
           exit(enumReturn_Codes::ERROR_CONV);
       }
       return intNumber;
   }

   ///Generate random numbers
   int genRandom(int intMin,int intMax)
   {
       assert(intMin < intMax);
       int intRange=intMax - intMin + 1;
       return rand()%intRange + intMin;
   }

  ///Place features of the game:Player,factory and parts
  void placeFeatures(struGameWorld& recworld)
  {
      assert(recworld.arrWorld!=nullptr);

      ///Place the player
      recworld.Player.row=genRandom(0, recworld.row/2);
      recworld.Player.col=genRandom(0,recworld.col/2);
      recworld.arrWorld[recworld.Player.row][recworld.Player.col]=enumFeatures::PLAYER;

      ///Place the factory
      int intFRow=genRandom(0,recworld.row-1);
      int intFCol=genRandom(0,recworld.col-1);
      while(recworld.arrWorld[intFRow][intFCol]==enumFeatures::PLAYER)
      {
         intFRow=genRandom(0,recworld.row-1);
         intFCol=genRandom(0,recworld.col-1);
      }
      recworld.arrWorld[intFRow][intFCol]=enumFeatures::FACTORY;

      ///Place the parts
      int intCount=0;
      while(intCount<=recworld.parts)
      {
          int intPRow=genRandom(0,recworld.row-1);
          int intPCol=genRandom(0,recworld.col-1);
          while((recworld.arrWorld[intPRow][intPCol]==enumFeatures::FACTORY) ||(recworld.arrWorld[intPRow][intPCol]==enumFeatures::PLAYER))
          {
              intPRow=genRandom(0,recworld.row-1);
              intPCol=genRandom(0,recworld.col-1);
          }
          recworld.arrWorld[intPRow][intPCol]=enumFeatures::PARTS;
          intCount++;
      }

  }



   ///Initialised the game and store values inside the variables
  struGameWorld makeWorld(int intRow,int intCol,int intParts)
  {

      struGameWorld recworld;
      recworld.row=intRow;
      recworld.col=intCol;
      recworld.parts=intParts;

      recworld.arrWorld=new t_1DArray[recworld.row];
      for(int a=0;a<recworld.row;a++)
      {
          recworld.arrWorld[a]=new int[recworld.col];
          for(int b=0;b<recworld.col;b++)
          {
              recworld.arrWorld[a][b]=enumFeatures::SPACE;
          }
      }
      placeFeatures(recworld);
      return recworld;
  }

  ///Display the game on the console
  void displayWorld(const struGameWorld& recworld);

  ///Ensuring that the player moves withnin  the world
  bool isInWorld(struGameWorld& recworld);

  ///Moving the player
  void movePlayer(struGameWorld& recworld);

  ///freeing allocated memory
  void deAllocateMemory(struGameWorld& recworld);










}
