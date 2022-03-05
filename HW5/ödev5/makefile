
output:	main.o Abstract.o Vector.o HexArray1D.o Template.o
	g++ -std=c++11 main.o Abstract.o Vector.o HexArray1D.o Template.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Abstract.o: Abstract.cpp Abstract.h
	g++ -std=c++11 -c Abstract.cpp

Vector.o:   Vector.cpp Vector.h
	g++ -std=c++11 -c Vector.cpp

HexArray1D.o:  HexArray1D.cpp HexArray1D.h
	g++ -std=c++11 -c HexArray1D.cpp

Template.o: Template.cpp Template.h
	g++ -std=c++11 -c Template.cpp

clean:
	rm *.o output



