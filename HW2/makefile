

output: main.o HM2_functions.o
	g++ main.o HM2_functions.o -o output
       
main.o: main.cpp
	g++ -std=gnu++11 -c main.cpp
	
HM1_functions.o: HM2_functions.cpp 
	g++ -std=gnu++11 -c HM2_functions.cpp
		 
clean:		 	      
	rm *.o output 
