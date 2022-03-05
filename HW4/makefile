

output: main.o HM4_functions.o
	g++ main.o HM4_functions.o -o output
       
main.o: main.cpp
	g++ -std=gnu++11 -c main.cpp
	
HM1_functions.o: HM4_functions.cpp 
	g++ -std=gnu++11 -c HM4_functions.cpp
		 
clean:		 	      
	rm *.o output 
