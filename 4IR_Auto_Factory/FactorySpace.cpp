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

  ///Display moving and general instructions of the game
  void displayInstr(struGameWorld& recworld)
  {
      cout<<endl;
      cout<<"**Instructions of the game**"<<endl;
      cout<<"Moves left <<"<<recworld.g_score<<">>"<<endl;
      cout<<"Parts carried <<"<<recworld.g_part<<">>"<<endl;
      cout<<"Press W to move UP"<<endl;
      cout<<"Press S to move DOWN"<<endl;
      cout<<"Press A to move LEFT"<<endl;
      cout<<"Press D to move RIGHT"<<endl;
      cout<<"Press X to exit the game"<<endl;
  }

  ///Display the game on the console
  void displayWorld(struGameWorld& recworld)
  {
      system("cls");

      for(int a=0;a<recworld.row;a++)
      {
          for(int b=0;b<recworld.col;b++)
          {
              cout<<CH_FEATURES[recworld.arrWorld[a][b]];
          }
          cout<<endl;
      }
      displayInstr(recworld);
  }

  ///Ensuring that the player moves withnin  the world
  bool isInWorld(struGameWorld& recworld)
  {
      if(recworld.Player.row<0) return false;
      if(recworld.Player.row>recworld.row-1) return false;
      if(recworld.Player.col<0) return false;
      if(recworld.Player.col>recworld.col-1) return false;
      if(recworld.arrWorld[recworld.Player.row][recworld.Player.col]==enumFeatures::FACTORY) return false;
      if((recworld.arrWorld[recworld.Player.row][recworld.Player.col]==enumFeatures::PARTS)&& recworld.g_part==1) return false;

      return true;
  }

  ///Moving the player
  void movePlayer(struGameWorld& recworld,char chInput)
  {
      int intDRow=recworld.Player.row;
      int intDCol=recworld.Player.col;
      switch(chInput)
      {
          case 'a':
          case 'A':
            {
               recworld.Player.col--;
               break;
            }
          case 'd':
          case 'D':
            {
                recworld.Player.col++;
                break;
            }
          case 'w':
          case 'W':
            {
                recworld.Player.row--;
                break;
            }
          case 's':
          case 'S':
            {
                recworld.Player.row++;
                break;
            }
          case 'x':
          case 'X':
            {
                cout<<"You have exited the game"<<endl;
                exit(enumReturn_Codes::EXIT);
            }
          default:
            {
                cerr<<"Inalid option <<"<<chInput<<">>"<<endl;
                exit(enumReturn_Codes::INVALID_INPUT);
            }
      }

       outcome(recworld);
      if(isInWorld(recworld))
      {
          recworld.arrWorld[recworld.Player.row][recworld.Player.col]=enumFeatures::PLAYER;
          recworld.arrWorld[intDRow][intDCol]=enumFeatures::SPACE;
          recworld.g_score--;
      }else{
          recworld.Player.row=intDRow;
          recworld.Player.col=intDCol;
      }





  }

  ///Stating whether the player has won or lost
  void outcome(struGameWorld& recworld)
  {

      if((recworld.arrWorld[recworld.Player.row][recworld.Player.col]==enumFeatures::PARTS) &&(recworld.g_part!=1))
      {
          recworld.arrWorld[recworld.Player.row][recworld.Player.col]=enumFeatures::SPACE;
          recworld.g_part++;
      }
  }

  ///freeing allocated memory
  void deAllocateMemory(struGameWorld& recworld)
  {
      assert(recworld.arrWorld != nullptr);
      for(int a=0;a<recworld.row;a++)
      {
          delete[] recworld.arrWorld[a];
      }
      delete[] recworld.arrWorld;
      recworld.arrWorld=nullptr;
  }










}
