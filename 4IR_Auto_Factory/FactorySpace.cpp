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
            exit(enumReturn_Codes::INVALID_ARGC)
        }
    }

}
