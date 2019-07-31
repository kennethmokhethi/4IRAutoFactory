#include "FactorySpace.h"

using namespace std;
using namespace factorySpace;
int main(int argc,char** argv)
{
    ///Ensuring the number of arguments are 4.
    validateArgs(argc,argv);

    ///Initialise the diminsions of the game and the number of parts.
    int intTRow=convertToInt(argv[1]);
    int intTCol=convertToInt(argv[2]);
    int intTParts=convertToInt(argv[3]);
    srand(time(nullptr));

    struGameWorld recworld=makeWorld(intTRow,intTCol,intTParts);
    bool blnContinue=true;
    bool blnWon=true;
    char chInput='\0';

    do{
       displayWorld(recworld);
       cin>>chInput;
       movePlayer(recworld,chInput);

       ///Changing the flag.
       if((recworld.g_score<0) || (recworld.parts<0))
       {
           blnContinue=false;
           blnWon=true;
       }

    }while(blnContinue);


    ///Stating the player won or lost.
     if(blnWon)
     {
         if(recworld.parts<0)
         {
             cout<<"**********************************************"<<endl;
             cout<<"********CONGRATULATIONS,YOU HAVE WON**********"<<endl;
             cout<<"**********************************************"<<endl;
             exit(enumReturn_Codes::WON);
         }else{
            cout<<"***********************************************"<<endl;
            cout<<"****YOU OUT OF PARTS,YOU LOST******************"<<endl;
            cout<<"***********************************************"<<endl;
             exit(enumReturn_Codes::LOST);

         }
     }

    return enumReturn_Codes::SUCCESS;
}
