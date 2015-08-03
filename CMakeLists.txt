cmake_minimum_required(VERSION 2.8)

project(projectLinkedTests)

#option(BUILD_TESTING "tests executable" ON)
#include(CTest)
#include(ExternalData)


option(fileCreation "fileCreation executable" ON)
option(findFile "findFile executable" ON)
option(listFiles "listFiles executable" ON)

if (fileCreation)
    add_subdirectory(fileCreation)
endif ()

if (findFile)
    add_subdirectory(findFile)
endif ()

if (listFiles)
    add_subdirectory(listFiles)
endif ()
