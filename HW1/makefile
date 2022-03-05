

output: main.o HM1_functions.o
	g++ main.o HM1_functions.o -o output
       
main.o: main.cpp
	g++ -std=gnu++11 -c main.cpp
	
HM1_functions.o: HM1_functions.cpp 
	g++ -std=gnu++11 -c HM1_functions.cpp
		 
clean:		 	      
	rm *.o output 
