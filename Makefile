output: main.o Select.o Widget.o
	g++ -g main.o Select.o Widget.o -o output 

main.o: src/main.cpp
	g++ -g -Wall -c src/main.cpp

Select.o: src/Select.cpp src/Select.hpp
	g++ -g -Wall -c src/Select.cpp

Widget.o: src/Widget.cpp src/Widget.hpp
	g++ -g -Wall -c src/Widget.cpp

clean:
	rm *.o output
