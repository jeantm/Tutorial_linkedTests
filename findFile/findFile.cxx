#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>


bool FindFile(const char * path);

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong inputs.\nPlease enter the path you want to search and the file you are looking for, in that order." <<std::endl;
        return EXIT_FAILURE;
    }
    else
    {
        std::cout << "You are looking for the file:\n\t" << argv[1] << std::endl;
        if(!FindFile(argv[1]))
        {
            std::cerr << "FAIL: File not found" << std::endl;
            return EXIT_FAILURE;
        }
        else
        {
            std::cout <<"SUCCESS: File found" << std::endl;
            return EXIT_SUCCESS;
        }
    }
}


bool FindFile(const char * path)

{
    std::ifstream myfile;
    myfile.open(path);
    if(!myfile)
    {
        std::cerr << path << " does not existe." << std::endl;
        return false;
    }
    else
    {
        myfile.close();
        return true;
    }
}
