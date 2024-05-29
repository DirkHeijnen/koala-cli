cmake_minimum_required(VERSION 3.7...3.22)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(APPLICATION_NAME koala_cli)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


project(${APPLICATION_NAME} VERSION 1.0
                            DESCRIPTION "Koala CLI tool"
                            LANGUAGES CXX)

add_subdirectory(src)



set(EXECUTABLE_NAME koala)
add_executable(${EXECUTABLE_NAME} main.cpp)
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_11)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE koala_lib)