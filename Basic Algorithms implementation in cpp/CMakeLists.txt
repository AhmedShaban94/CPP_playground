cmake_minimum_required(VERSION 2.4)

project(Basic_Algorithms_Implementation_in_cpp)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/src) 

file(GLOB SOURCE "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/include/*.hpp" "${PROJECT_SOURCE_DIR}/include/*.h") 

add_executable(basic_algorithms ${SOURCE} ${HEADERS})  

set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install") 

install (TARGETS basic_algorithms RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING
      "Choose the type of build, options are: Debug Release
       RelWithDebInfo MinSizeRel."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

