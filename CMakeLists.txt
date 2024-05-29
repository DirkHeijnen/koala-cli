cmake_minimum_required(VERSION 3.7...3.22)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create Koala Library from src and include folders.
set(LIBRARY_NAME koala_lib)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ./include/*.hpp)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ./src/*.cpp)
add_library(${LIBRARY_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${LIBRARY_NAME} PRIVATE src PUBLIC include)


# Create Koala executable from main file + library
set(APPLICATION_NAME koala)
project(${APPLICATION_NAME} VERSION 1.0 DESCRIPTION "Koala CLI tool" LANGUAGES CXX)
add_executable(${APPLICATION_NAME} main.cpp)
target_link_libraries(${APPLICATION_NAME} PUBLIC ${LIBRARY_NAME})