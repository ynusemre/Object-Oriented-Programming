

output: main.o HM3_functions.o
	g++ main.o HM3_functions.o -o output
       
main.o: main.cpp
	g++ -std=gnu++11 -c main.cpp
	
HM1_functions.o: HM3_functions.cpp 
	g++ -std=gnu++11 -c HM3_functions.cpp
		 
clean:		 	      
	rm *.o output 
