//YunusEmreGeyik-1801042635
#include "HM3.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace  std;

/*I compare the number of marked cells between the first game and the second game. 
If there is more in the first game, the compare function returns true, 
if there is more in the second game, it returns false.*/
int main(){
	Hex game1;
	game1.menu();
	game1.compare(game1);
	Hex::hold4=0;
	Hex::hold5=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	cout<<endl<<endl<<"THE SECOND GAME"<<endl<<endl;
	Hex game2;
	game2.menu();
	bool Result=game2.compare(game2);

	if(Result==true){
		cout<<endl<<"the first game has more marked cells"<<endl;
	}
	if(Result==false){
		cout<<endl<<"the second game has more marked cells."<<endl;
	}
	if(Result==false && Hex::hold1==Hex::hold2){
		cout<<endl<<"has an equal number of marked cells in the two games."<<endl;
	}
	
	return 0;
}