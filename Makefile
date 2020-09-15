### variables ##############

CXX        = g++
CXXFLAGS   = -g -Wall -fpic
OBJECTS    = main.o Select.o MultiSelect.o List.o Text.o InputPassword.o
LIBRARYOBJ = Select.o MultiSelect.o List.o Text.o InputPassword.o

############################ 

output: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o output $(OBJECTS) 

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp

Select.o: src/Select.cpp src/Select.hpp
	$(CXX) $(CXXFLAGS) -c src/Select.cpp

MultiSelect.o: src/MultiSelect.cpp src/MultiSelect.hpp
	$(CXX) $(CXXFLAGS) -c src/MultiSelect.cpp

List.o: src/List.cpp src/List.hpp
	$(CXX) $(CXXFLAGS) -c src/List.cpp

Text.o: src/Text.cpp src/Text.hpp
	$(CXX) $(CXXFLAGS) -c src/Text.cpp

InputPassword.o: src/InputPassword.cpp src/InputPassword.hpp
	$(CXX) $(CXXFLAGS) -c src/InputPassword.cpp

############################

static: $(LIBRARYOBJ)
	ar -rs libCliWidgets.a $(LIBRARYOBJ)

dynamic: $(LIBRARYOBJ)
	$(CXX) -shared -o libCliWidgets.so $(LIBRARYOBJ)

############################

# To prevent make from getting confused by an actual file called clean, me may use .PHONY:
# The "-" in -rm causes make to continue in spite of errors from rm
.PHONY: clean
clean:
	-rm $(OBJECTS) output libCliWidgets.a libCliWidgets.so
