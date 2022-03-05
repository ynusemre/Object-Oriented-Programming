//YunusEmreGeyik-1801042635
#include "HM4.h"
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace  std;

/*I compare the number of marked cells between the first game and the second game with the operator. 
If there is more in the first game, the compare function returns true, 
if there is more in the second game, it returns false.
if they are equal,i indicate that situation.
*/
int main(){
	int x1=0,x2=0,x3=100;
	Hex game1(x1,x3);
	game1.menu(x2);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	int counter=0;
	cout<<endl<<endl<<"THE SECOND GAME"<<endl<<endl;
	Hex game2(x1,x3);
	game2.menu(x2);
	
	bool Result=game2==game1;

	cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

	if(Result==true){
		cout<<endl<<"the first game has more marked cells"<<endl;
	}
	if(Result==false && x2==18){
		cout<<endl<<"has an equal number of marked cells in the two games."<<endl;
		counter++;
	}
	if(Result==false && counter==0){
		cout<<endl<<"the second game has more marked cells."<<endl;
	}
	return 0;
}