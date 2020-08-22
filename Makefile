output: main.o Select.o
	g++ -g main.o Select.o -o output

main.o: src/main.cpp
	g++ -g -Wall -c src/main.cpp

Select.o: src/Select.cpp src/Select.hpp
	g++ -g -Wall -c src/Select.cpp

clean:
	rm *.o output
