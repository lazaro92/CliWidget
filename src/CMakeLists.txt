# specify minimun cmake version (3.0 minimum for newer projects)
cmake_minimum_required(VERSION 3.2)

# specify project information: name, version and language
project(Cliwidget VERSION 0.1.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# creates the executable for testing
add_executable(Test 
	main.cpp
	ColorsEnum.hpp
	InputPassword.cpp InputPassword.hpp
	List.cpp List.hpp
	MultiSelect.cpp MultiSelect.hpp
	Select.cpp Select.hpp
	Text.cpp Text.hpp
	)

# creates the library, for making a shared library pass -DBUILD_SHARED_LIBS=YES to the cmake command 
add_library(CliWidget
	ColorsEnum.hpp
	InputPassword.cpp InputPassword.hpp
	List.cpp List.hpp
	MultiSelect.cpp MultiSelect.hpp
	Select.cpp Select.hpp
	Text.cpp Text.hpp
    )
