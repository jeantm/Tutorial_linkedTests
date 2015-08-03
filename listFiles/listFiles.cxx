#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>


int getpath (std::string path, std::vector<std::string> &files);

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cerr << "Please enter the absolute PATH to the directory you want to search." <<std::endl;
        return EXIT_FAILURE;
    }
    else
    {
        std::vector<std::string> files = std::vector<std::string>();
        std::string path = std::string(argv[1]);
        getpath(path,files);

        std::cout <<"Files found in directory:" << std::endl;
        for (unsigned int i = 0;i < files.size();i++) {
            std::cout << "\t- " << files[i] << std::endl;
        }
        return EXIT_SUCCESS;
    }
}


int getpath (std::string path, std::vector<std::string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(path.c_str())) == NULL) {
        std::cerr << "Wrong path" <<std::endl;
        return -1;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(std::string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}
