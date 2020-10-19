# specify minimun cmake version (3.0 minimum for newer projects)
cmake_minimum_required(VERSION 3.2)

# specify project information: name, version and language
project(Cliwidget VERSION 0.1.0 LANGUAGES CXX)

# creates the executable for testing
add_executable(Test main.cpp)

# creates the library, for making a shared library pass -DBUILD_SHARED_LIBS=YES to the cmake command 
add_library(CliWidget
    InputPassword.cpp
    List.cpp
    MultiSelect.cpp
    Select.cpp
    Text.cpp
    )
