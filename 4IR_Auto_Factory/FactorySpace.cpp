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





}
