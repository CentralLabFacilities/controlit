cmake_minimum_required(VERSION 2.8.3)
project(controlit_controller_library)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    roscpp
    cmake_modules
    controlit_core
    controlit_cmake
)

# message("** controlit_cmake_DIR: " ${controlit_cmake_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../controlit/controlit_cmake/Modules)
# message("** CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH})

include(controlitbuild)
controlit_build_init()

find_package(Eigen REQUIRED)
find_package(Rbdl REQUIRED)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
#    CATKIN_DEPENDS controlit_core
#    DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
    include
    ${EIGEN_INCLUDE_DIRS}
    ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
file(GLOB SRCS src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SRCS})

## Declare a cpp executable
# add_executable(controlit_node src/controlit_node.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(controlit_node controlit_generate_messages_cpp)
add_dependencies(${PROJECT_NAME} controlit_core)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY plugins/
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

# Add the ControlIt!-specific build options and macros
# rosbuild_find_ros_package(controlit_cmake)
# list(APPEND CMAKE_MODULE_PATH ${controlit_cmake_PACKAGE_PATH}/cmake)
# include(controlitbuild)
# controlit_build_init()

# Boost dependency: boost-signals
# rosbuild_add_boost_directories()

# find Eigen/RBDL
# controlit_build_depend_rbdl()

# find muParser
# controlit_build_depend_mu_parser()

# find Yaml-cpp
# controlit_build_depend_yaml()

# #set the default path for built executables to the "bin" directory
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# #set the default path for built libraries to the "lib" directory
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
# rosbuild_gensrv()

# file(GLOB SRCS src/*.cpp)
# rosbuild_add_library (${PROJECT_NAME} SHARED ${SRCS})
# rosbuild_link_boost(${PROJECT_NAME} signals system filesystem)
# controlit_build_link_depends(${PROJECT_NAME})

# TESTS!
# add_subdirectory(tests)
