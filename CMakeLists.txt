cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# specify project information: name, version and language
project(Cliwidget VERSION 0.2.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# creates the executable for testing
# add_executable(Test 
# 	main.cpp
#	ColorsEnum.hpp
#	InputPassword.cpp InputPassword.hpp
#	List.cpp List.hpp
#	MultiSelect.cpp MultiSelect.hpp
#	Select.cpp Select.hpp
#	Text.cpp Text.hpp
#	)



# creates the library, for making a shared library pass -DBUILD_SHARED_LIBS=YES to the cmake command 
add_library(CliWidget
    Source/InputPassword.cpp
    Source/List.cpp
    Source/MultiSelect.cpp
    Source/Select.cpp
    Source/Text.cpp
    )

target_include_directories(CliWidget
    PRIVATE
        "${PROJECT_BINARY_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/Include"
    )
