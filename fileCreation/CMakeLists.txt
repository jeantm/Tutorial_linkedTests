cmake_minimum_required(VERSION 2.8)

project(fileCreation)

# Find SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})
include(${GenerateCLP_USE_FILE})

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

SEMMacroBuildCLI(
    NAME fileCreation
    EXECUTABLE_ONLY
    TARGET_LIBRARIES ${ITK_LIBRARIES}
)


