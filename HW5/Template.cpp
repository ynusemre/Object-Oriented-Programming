#include "Template.h"
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <deque>
using namespace  std;

namespace Abstract_Class{
	template<template<typename...> class T>
	HexAdapter<T>::HexAdapter(const HexAdapter<T> &object) :AbstractHex(object){       //Copy Constructor.
		hexCells.resize(this->number);

		for(int i=0;i<this->number;i++){
			hexCells[i].resize(this->number);
		}
		hexCells=object.hexCells;
	}
	//Copy Assignment Operator.
	template<template<typename...> class T>                                     
	HexAdapter<T>& HexAdapter<T>::operator=(const HexAdapter<T> &object){
		AbstractHex::operator=(object);
		
		if(this == &object){
			return *this;
		}
		else{
			hexCells.resize(this->number);

			for(int i=0;i<this->number;i++){
				hexCells[i].resize(this->number);
			}
			hexCells=object.hexCells;

			return *this;
		}	
	}
	template<template<typename...> class T>
	HexAdapter<T>::~HexAdapter(){                           //Destructor for the HexVector class.
		if(hold5!=0){
			if(ctr4==0){
				delete []arr5;
				delete []arr6;
				delete []arr7;
				delete []arr8;
				delete []arr;
				delete []APtr;
				ctr4++;
			}	
		}}
	template<template<typename...> class T>
	/*the function that finds out which player won the game. The winner of the game is determined.*/	
	bool HexAdapter<T>::isEnd(const int &r)const{
		int counter10=0,counter11=0,counter12=0,counter13=0;
		
		if(r==0){
			for(int i=0;i<number;i++){
				for(int j=0;j<number;j++){
					if(hexCells[i][j].getCell()==1 && hexCells[i][j].getRow()==1){
						counter10++;
						break;
					}}}
			for(int i=0;i<number;i++){
				for(int j=0;j<number;j++){		
					if(hexCells[j][i].getCell()==2 && hexCells[j][i].getRow()==2){
						counter11++;
						break;
					}}}		
			if(counter10==number){
				return true;
			}
			if(counter11==number){
				return true;
			}}
		if(r==1){
			for(int i=0;i<number;i++){
				for(int j=0;j<number;j++){
					if(hexCells[i][j].getCell()==1 && hexCells[i][j].getRow()==1){
						counter12++;
						break;
					}}}
			for(int i=0;i<number;i++){
				for(int j=0;j<number;j++){		
					if(hexCells[j][i].getCell()==2 && hexCells[j][i].getRow()==2){
						counter13++;
						break;
					}}}		
			if(counter12==number){
				return true;
			}
			if(counter13==number){
				return true;
			}}
		return false;	
	}
	template<template<typename...> class T>
	/*I call the inline function in a for loop while printing the last state of the board.
		It helps to print the board using the vector and enum structure.*/
	inline void HexAdapter<T>::control(const int &i,const int &j)const{
		int counter=0,counter2=0;
		CellState cell1=dot;
		CellState cell2=cross;
		CellState cell3=circle;

		if(hexCells[i][j].getCell()==cell2 && hexCells[i][j].getRow()==cell2){
			cout<<" X ";
			counter++;
		}
		if(hexCells[i][j].getCell()==cell3 && hexCells[i][j].getRow()==cell3){
			cout<<" O ";
			counter2++;
		}
		if(hexCells[i][j].getCell()==cell1 && hexCells[i][j].getRow()==cell1 && counter==0 && counter2==0){
			cout<<" . ";
		}}
	template<template<typename...> class T>	
	/*the operator that prints the current state of the game board.*/	
	void HexAdapter<T>::print()const{
		int k=0,t=0;
		
		char arr[7]="O SIDE";
		t=number+1;
		
		for(int i=0;i<number;i++){
			if(i==0){
				cout<<"-----------X SIDE-----------"<<endl;
				cout<<"     ";
										
				for(char i=65;i<65+number;i++){
					cout<<i<<"  ";
				}
				cout<<endl;
			}
			if(i<6){
				cout<<arr[i]<<"  ";
				cout<<i+1;
			}
			if(i>=6){
				cout<<"   "<<i+1;
			}
			for(int k=0;k<i;k++){
				cout<<"  ";
			}
			for(int j=0;j<number;j++){
				control(i,j);
			}
			for(int j=0;j<number;j++){
				if(j==number-1){
					for(;t>0;t--){
						cout<<"  ";
					}
					if(i<6){
						cout<<arr[i];
					}
					t=number-i;
				}}
			if(i==number-1){
				cout<<endl;
				cout<<"-----------X SIDE-----------"<<endl;
			}
			cout<<endl;
		}}

	template<template<typename...> class T>
	/*
	I am  saving it in the file.

	in the first line, I am saving who is on the turn.if there is one the turn is user1 or user,if there is two the turn is user2 
	if any user use the save command,the game is saving and  the turn is his.

	On the second line, I am saving the board size.
	In the third line, I am saving the number of moves of user1.
	In the fourth line, I am saving the number of moves of user2.

	thanks to the fifth line, I am saving who the game is playing against.if there is three the game is user1VSuser2,
	if there is four the game is userVScomputer.

	On the sixth line, I am saving the coordinates of user1's moves.
	On the seventh line, I am saving the coordinates of user2's moves.
	Thanks to the other lines, I am saving the last state of the game board on the screen*/		
	void HexAdapter<T>::writeFromFile(string file_name,char arr[7],int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &number,int f,int l,int wch_user,int who_vs_who){
		ofstream file;
		string str;
		file.open(file_name);
		
		if(!file.is_open()){
			cout<<"The file hasn't opened."<<endl;
			exit(0);
		}
		int counter=0,counter2=0;
		int t=number+1;
		
		file<<wch_user<<endl;
		file<<number<<endl;
		file<<f<<endl;
		file<<l<<endl;
		file<<who_vs_who<<endl;
		
		if(wch_user==1){
			if(number>=10){
				for(int i=0;i<f;i++){
					if(i==f-1){
						file<<arr5[i]<<","<<arr6[i]<<":";
						break;
					}
					file<<arr5[i]<<","<<arr6[i]<<".";

				}
				file<<endl;
				for(int i=0;i<l;i++){
					if(i==l-1){
						file<<arr7[i]<<","<<arr8[i]<<":";
						break;
					}	
					file<<arr7[i]<<","<<arr8[i]<<".";
				}
				file<<endl;
			}
			else{
				for(int i=0;i<f;i++){
					if(i==f-1){
						file<<arr5[i]<<arr6[i]<<":";
						break;
					}
					file<<arr5[i]<<arr6[i];

				}
				file<<endl;
				for(int i=0;i<l;i++){
					if(i==l-1){
						file<<arr7[i]<<arr8[i]<<":";
						break;
					}	
					file<<arr7[i]<<arr8[i];
				}
				file<<endl;
			}}
		if(wch_user==2){
			if(number>=10){
				for(int i=0;i<f;i++){
					if(i==f-1){
						file<<arr5[i]<<","<<arr6[i]<<":";
						break;
					}
					file<<arr5[i]<<","<<arr6[i]<<".";

				}
				file<<endl;
				for(int i=0;i<l;i++){
					if(i==l-1){
						file<<arr7[i]<<","<<arr8[i]<<":";
						break;
					}	
					file<<arr7[i]<<","<<arr8[i]<<".";
				}
				file<<endl;
			}
			else{
				for(int i=0;i<f;i++){
					if(i==f-1){
						file<<arr5[i]<<arr6[i]<<":";
						break;
					}
					file<<arr5[i]<<arr6[i];
				}
				file<<endl;
				for(int i=0;i<l;i++){
					if(i==l-1){
						file<<arr7[i]<<arr8[i]<<":";
						break;
					}	
					file<<arr7[i]<<arr8[i];
				}
				file<<endl;
			}}
		CellState cell1=dot;
		CellState cell2=cross;
		CellState cell3=circle;

		for(int i=0;i<number;i++){
			if(i==0){
				file<<"-----------X SIDE-----------"<<endl;
				file<<"     ";
													
				for(char i=65;i<65+number;i++){
					file<<i<<"  ";
				}
				file<<endl;
			}
			if(i<6){
				file<<arr[i]<<"  ";
				file<<i+1;
			}
			if(i>=6){
				file<<"   "<<i+1;
			}
			for(int k=0;k<i;k++){
				file<<"  ";
			}
			/*Thanks to the enum structure, I press the game board to the screen.*/
			for(int j=0;j<number;j++){
				counter=0,counter2=0;

				if(hexCells[i][j].getCell()==cell2 && hexCells[i][j].getRow()==cell2){
					file<<" X ";
					counter++;
				}
								
				if(hexCells[i][j].getCell()==cell3 && hexCells[i][j].getRow()==cell3){
					file<<" O ";
					counter2++;
				}

				if(hexCells[i][j].getCell()==cell1 && hexCells[i][j].getRow()==cell1 && counter==0 && counter2==0){
					file<<" . ";
			}}
			for(int j=0;j<number;j++){
				if(j==number-1){
					for(;t>0;t--){
						file<<"  ";
					}
					if(i<6){
						file<<arr[i];
					}
					t=number-i;
				}}
				if(i==number-1){
					file<<endl;
					file<<"-----------X SIDE-----------"<<endl;
				}
				file<<endl;
			}
		file.close();
	}
	template<template<typename...> class T>
	/*The operator that compares the game of the first opened object with the game of the second opened object.
		for the their Game Boards are equal or no equal.Returns true if the games have a same Game Board.*/
	bool HexAdapter<T>::operator==(const HexAdapter<T> &object)const{
		if(number!=object.number){
			return false;
		}
		int counter=0;
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				if(hexCells[i][j].getCell()!=object.hexCells[i][j].getCell() && hexCells[i][j].getRow()!=object.hexCells[i][j].getRow()){
					counter++;
					break;
				}}}
		if(counter!=0){
			return false;
		}	
		return true;
	}

	template<template<typename...> class T>
	void HexAdapter<T>::reset(){
		hexCells.resize(number);

		for(int i=0;i<number;i++){
			hexCells[i].resize(number);
		}

		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				hexCells[i][j].setter(0);
		}}
		for(int i=0;i<100;i++){
			arr5[i]=0;
		}
		for(int i=0;i<100;i++){
			arr6[i]=0;
		}
		for(int i=0;i<100;i++){
			arr7[i]=0;
		}
		for(int i=0;i<100;i++){
			arr8[i]=0;
		}
		f=0;
		l=0;
		h1=0;
		h2=0;
		print();
	}
	template<template<typename...> class T>
	void HexAdapter<T>::setSize(){
		int number4=0;
		int counter=0,counter2=0;
		
		while(true){
			counter=0;
			cout<<"Plaese enter size of board(line X column)(6x6,7x7, 8x8, 9x9, 10x10, 11x11 or 12x12):"<<endl;
			
			cout<<"Line:";
			cin>>number;
					
			cout<<"Column:";
			cin>>number4;
			setNumber(number);
			number=getNumber();
			if(number>=5 && number4>=5 && number==number4){
				break;
			}
			if(counter==0){
				if (!(number) || !(number4)){
					cout <<endl<<"Please enter numbers only."<<endl;
					cin.clear();
					cin.ignore(100,'\n');
					counter+=1;
				}}
			
			if(number<5 && number4<5 && counter==0){
				cout<<"Please enter right board size(line and column)"<<endl<<endl;
				counter2++;
			}
			
			if(number!=number4 && counter==0 && counter2==0){
				cout<<"Please enter right board size(line and column)"<<endl<<endl;
			}}
	///////////////////////////////////////////////////////////////////////////////////////////////////////
		reset();
	}
	template<template<typename...> class T>
	//Function that returns the given coordinate
	/*I used the move made by the computer to press the screen.*/
	typename HexAdapter<T>::Cell HexAdapter<T>::operator()(const int &x,const int &y)const{
		HexAdapter<T>::Cell cells;
		cells.setRow(x);
		cells.setCell(y);

		int counter=0;
		
		CellState cell1=dot;
		CellState cell2=cross;
		CellState cell3=circle;
		
		if(hexCells[x-1][y].getCell()==cell2 && hexCells[x-1][y].getRow()==cell2){
			counter++;
		}
		if(hexCells[x-1][y].getCell()==cell3 && hexCells[x-1][y].getRow()==cell3){
			counter++;
		}
		
		if(counter==0){
			throw OperatorMistake("!!!There is no any Move at this coordinates!!!");
		}

		return cells;
	}
	template<template<typename...> class T>
	//Function that returns the last move in the game.
	typename HexAdapter<T>::Cell HexAdapter<T>::lastMove()const{
		HexAdapter<T>::Cell cells;
		cells.setRow(h1);
		cells.setCell(h2);
		int ctr6=0;
		
		if(h1==0 && h2==0){
			ctr6++;
		}
		if(ctr6!=0){
			throw "!!!There is no Last Move!!!";
		}
		else{
			return cells;
		}
	}
	
	template<template<typename...> class T>
	//for Computer
	/*The computer randomly puts its moves in 6 directions around the coordinates entered by the user. 
	If the user puts X in a coordinate which has full 6 directions on the game board, 
	then the computer puts another part of the board that is currently empty.
	I used vector as an extra in this assignment.
	And  it returns the Cell.
	*/	
	typename HexAdapter<T>::Cell HexAdapter<T>::play()const{
		int counter8=0;
		
		int z=0,k=0;
		char num2;
		int num3=0,flag4=1,m=0,flag2=1,flag=1,counter7=0,y=0,t=0,l=0;
		int arr3[100];
		char arr4[100];
		int number3=0,num4=0;
		char num1[15];
		HexAdapter<T> :: Cell cells3;
		for(int i=0;i<number;i++){
			arr3[i]=i+1;
		}
		for(int i=65;i<65+number;i++){
			arr4[y]=i;
			y++;
		}
		num3=HexAdapter<T>::c;
		num1[0]=HexAdapter<T>::d;
		
		while(flag4!=0){
			int counter3=0,counter4=0,counter5=0,counter6=0,counter12=0;
							
			if(counter7==0){
				cout<<"Computer:";
			}
			counter7+=1;
				
			unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
				default_random_engine e(seed);
				uniform_int_distribution<int> distr(0,7);
				counter8=distr(e);				
				//Sağ
				if(counter8==0){
					num4=num3;
					num2=num1[0]+1;
					number3=(int)num2-65;
				}
				//sol
				if(counter8==1){
					num4=num3;
					num2=num1[0]-1;
					number3=(int)num2-65;
				}
				//sol-üst
				if(counter8==2){
					num4=num3-1;
					num2=num1[0];
					number3=(int)num2-65;
				}
				//sağ-üst
				if(counter8==3){	
					num4=num3-1;
					num2=num1[0]+1;
					number3=(int)num2-65;
				}
				//sol-alt çapraz
				if(counter8==4){	
					num4=num3+1;
					num2=num1[0]-1;
					number3=(int)num2-65;
				}
				//sağ-alt çapraz
				if(counter8==5){	
					num4=num3+1;
					num2=num1[0];
					number3=(int)num2-65;
				}
				//random
				if(counter8==6){
					int initial=1;
					int last=number+1;
					int result1=last-initial;
								
					char initial2=65;
					char last2=65+number;
					char result2=last2-initial2;
					
					uniform_int_distribution<int> distr2(1,result1);
					uniform_int_distribution<char> distr3(65,result2);
					num4=distr2(e);
					num2=distr3(e);
					number3=(int)num2-65;
				}
				for(int p=0;p<b+1;p++){
					if(num4==arr5[p] && number3==arr6[p]){
						counter5+=1;
						counter7+=1;
					}}
				for(int p=0;p<b;p++){	
					if(num4==arr7[p] && number3==arr8[p]){
						counter6+=1;
						counter7+=1;
					}}
				for(int i=0;i<number;i++){
					if(num4==arr3[i]){
						counter4+=1;
					}}
				y=0;
				for(int i=65;i<65+number;i++){ 
					if(num2==arr4[y]){
						counter3+=1;
					}
					y++;
				}
			if(counter4==1 && counter3==1 && counter5+counter6==0){
				h1=num4;
				h2=number3;
				cells3.setRow(num4);
				cells3.setCell(number3);
				flag4=0;
				//cout<<num2<<num4<<endl;
				
			}
			b++;
		}
		return cells3;
	}		
	template<template<typename...> class T>
	/*the players who make the X and O moves in the game.
	Score function adjusted according to how close they are to winning.
	For example, on a 6x6 game board. 
	If the player making X moves made 5 moves from top to bottom, the score is 5 for its
	And if his score is 6, he already wins the game.
	*/			
	int *HexAdapter<T>::score()const{
		int counter1=0,counter2=0;
		int *arr18=nullptr;
		arr18=new int[2];
		CellState cell1=dot;
		CellState cell2=cross;
		CellState cell3=circle;
		
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				if(hexCells[i][j].getCell()==cell2 && hexCells[i][j].getRow()==cell2){
					counter1++;
					break;
				}}}	
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				if(hexCells[j][i].getCell()==cell3 && hexCells[j][i].getRow()==cell3){
					counter2++;
					break;
				}}}	

		arr18[0]=counter1;
		arr18[1]=counter2;
		
		return arr18;
	}
	template<template<typename...> class T>
	//for User
	/*the function I created for the moves made by the users.*/
	void HexAdapter<T>::play(int &number2,int num3){
		int counter10=0,counter11=0,counter12=0;
		
		e=number;
		
		char *num1=nullptr;
		num1=new char[15];
		int num4=0,num5=0,num6=0,num9=0,num10=0,num11=0;
		int g=0,m=0;
		int x=0,d=0,z=0,k=0;
		int ctr1=0,ctr2=0;
		int nbr=0,nbr2=0;
		
		int x2=0;
		if(number2==0){
			ctr3=0;
		}
		if(number2==1){
			ctr3=1;
		}
		int arr3[100];
		char arr4[100];
		int number3=0,y=0,num7=0,t=0;
		
		if(nbr==1){
			ctr1=1;
			number=nbr2;
		}
		if(nbr==2){
			ctr2=1;
			number=nbr2;
		}
		if(nbr==0){
			ctr1=1;
			ctr2=1;
			
			for(int i=0;i<number;i++){
				arr3[i]=i+1;
			}
			for(int i=65;i<65+number;i++){
				arr4[y]=i;
				y++;
			}
			hexCells.resize(number);

			for(int i=0;i<number;i++){
				hexCells[i].resize(number);
			}

			for(int i=0;i<number;i++){
				for(int j=0;j<number;j++){
					hexCells[i][j].setter(0);
				}}}
		
		int flag2=1;
		
		g=f;
		m=l;
		
		while(flag2!=0){
			int flag3=1,flag4=1;
	////////////////////////////////////////////(USER)/////////////////////////////////////////////////////////////////  			
			while(flag3!=0 && ctr1==1){
				int counter3=0,counter4=0,counter5=0,counter6=0,counter10=0,counter13=0,counter14=0,counter15=0,counter16=0,counter18=0;
				num9=0,num10=0,num11=-1;
				auto flag5=flag3;
	//////////*I want the coordinates for X from the first user.*////////////	
				char file_name2[20];
				
				while(flag5!=0){
					/*I write the user that she can use the SAVE and LOAD commands if they want.*/
					cout<<endl<<endl<<"//////////////////////////////////////////////////////////////////////////////////////"<<endl;
					cout<<endl<<"!!!Please write SAVE or LOAD for save or load the current game status!!!"<<endl;
					cout<<"!!!Please write RESET for Reset the Game Board!!!"<<endl;
					cout<<"!!!Please write SET for Set the Game Board Size!!!"<<endl;
					cout<<"!!!Please write LAST for See the Last Move!!!"<<endl;
					//cout<<"!!!Please write FIND for Find the any Moves!!!"<<endl;
					if(ctr3==1){
						cout<<"USER(X)=";
					}
					if(ctr3==0){
						if(counter17%2==0){
							cout<<"USER1(X)=";
						}
						if(counter17%2==1){
							cout<<"USER2(O)=";
						}}
					cin>>num1;
					int cntr1=0,cntr2=0;
					counter13=0;
					
					number2=(int)num1[0]-65;
					num3=(int)num1[1]-48;
					num9=(int)num1[2]-48;
					num11=(int)num1[3]-48;
					/*If the user has entered the RESET command,
					i reset the game board. */
					if(num1[0]=='R' && num1[1]=='E' && num1[2]=='S' && num1[3]=='E'  && num1[4]=='T'){
						reset();
						counter14=0;
						counter15=0;
						counter13++;
						counter18++;
						cntr1=1;
					}
					/*If the user has entered the SET command,
					i ask user for the new game board size. */
					if(num1[0]=='S' && num1[1]=='E' && num1[2]=='T'){
						setSize();
						y=0;
						for(int i=0;i<number;i++){
							arr3[i]=i+1;
						}
						for(int i=65;i<65+number;i++){
							arr4[y]=i;
							y++;
						}
						counter14=0;
						counter15=0;
						counter13++;
						counter18++;
						cntr1=1;
					}
					/*If the user has entered the LAST command,
					i press to screen the last move*/	
					if(num1[0]=='L' && num1[1]=='A' && num1[2]=='S' && num1[3]=='T'){
						HexAdapter<T>::Cell cells6;
						
						try{
							cells6=lastMove();
							cout<<"Last Move: "<<arr4[cells6.getCell()]<<cells6.getRow();

						}
						catch(const char *mistake){
							cout<<mistake<<endl;
						}
						counter15++;
						counter13++;
						cntr1=1;
					}
					/*If the user has entered the SAVE command, 
					I am saving the last image of the game and the latest information of the game.*/
					if(num1[0]=='S' && num1[1]=='A' && num1[2]=='V' && num1[3]=='E'){
						
						cin>>file_name2;	
						file_name=file_name2;
						if(ctr3==0){
							if(counter17%2==0){
								writeFromFile(file_name,arr,arr5,arr6,arr7,arr8,number,f,l,1,3);
							}
							if(counter17%2==1){
								writeFromFile(file_name,arr,arr5,arr6,arr7,arr8,number,f,l,2,3);
							}
						}
						if(ctr3==1){

							//l=Hex::a;
							writeFromFile(file_name,arr,arr5,arr6,arr7,arr8,number,f,l,1,4);
						}	
						cntr1=1;
						counter15++;
					}
					/*If the user uses the LOAD command, the final state of the game in the entered file name is printed on the screen. 
					And  game is continued  with The that game.*/
					if(num1[0]=='L' && num1[1]=='O' && num1[2]=='A' && num1[3]=='D'){
						char file_name3[20];
						cin>>file_name3;
									
						int num8=0,counter=0;
						
						for(int i=0;i<100;i++){
							arr5[i]=0;
						}
						for(int i=0;i<100;i++){
							arr6[i]=0;
						}
						for(int i=0;i<100;i++){
							arr7[i]=0;
						}
						for(int i=0;i<100;i++){
							arr8[i]=0;
						}
						y=0;
						f=0;
						l=0;
						file_name=file_name3;
						readFromFile(arr5,arr6,arr7,arr8,num7,num8,f,l,who_vs_who);
						/*When a txt file is loaded, 
						I check immediately after the load function whether the loaded game is a valid game or not.
						If there is a valid game situation, the game continues. 
						If there is no valid game situation,the game ends.*/
						if(isValid(this)==true){
							cout<<"This game is valid.You can continue..."<<endl<<endl;
						}
						if(isValid(this)==false){
							cout<<"This game is not valid.You can not continue..."<<endl;
							flag2=0;
							flag3=0;
							flag5=0;
							counter++;
							counter15++;
							counter13++;
						}

						if(counter==0){
							number=num8;
						
							f=f;
							l=l;

							int x1=Current_With(num8);
							int x2=Current_height(num8);
							cout<<endl<<"The current width:"<<x1<<endl;
							cout<<"The current height:"<<x2<<endl;
							
							int count18=HexAdapter<T>::numberofMoves(f,l);
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
							
							y=0;
							for(int i=0;i<number;i++){
								arr3[i]=i+1;
							}
							for(int i=65;i<65+number;i++){
								arr4[y]=i;
								y++;
							}
							hexCells.resize(number);

							for(int i=0;i<number;i++){
								hexCells[i].resize(number);
							}

							for(int i=0;i<number;i++){
								for(int j=0;j<number;j++){
									hexCells[i][j].setter(0);
								}
							}
							g=f;
							/*If who_vs_who 4 is coming, the status of the players is changing.
								I switch to the User_vs_Computer function*/
							if(who_vs_who==4){
								if(num7==1){
									cout<<"The turn was at User."<<endl;
								}
								///////////////////////////////////////////////////h=who_vs_who;
								ctr3=1;	

								nbr=num7;
								nbr2=num8;
								
								flag5=0;
								counter13++;
								counter16++;
								h1=arr5[l];
								h2=arr6[l];
							}
							if(who_vs_who==3){
								if(num7==1){
									counter17=0;
									cout<<"The turn was at User1."<<endl;
									counter13++;
									flag5=0;
									nbr=1;
									h1=arr5[f];
									h2=arr6[f];
								}
								if(num7==2){
									counter17=1;
									cout<<"The turn was at User2."<<endl;
									flag3=0;
									flag5=0;
									counter13++;
									nbr=2;
									h1=arr5[l];
									h2=arr6[l];
								}
								///////////////////////////////////////////////////h=who_vs_who;
								ctr3=0;	

								nbr=num7;
								nbr2=num8;
								f=f;
								l=l;
								counter13++;
								counter16++;
							}
							num5=0;
							if(num7==1 && counter16==0){
								counter17=0;
								cout<<"The turn was at User1."<<endl;
								counter13++;
								flag5=0;
								nbr=1;
							}
							if(num7==2 && counter16==0){
								counter17=1;
								cout<<"The turn was at User2."<<endl;
								flag3=0;
								flag5=0;
								counter13++;
								nbr=2;
							}
							cntr2=1;
							counter15++;
						}	
					}
					
					if(num11>=0 && num11<10 && counter15==0){
						flag5=0;
						cout<<"Please,pay attention to the number you entered"<<endl;
						counter13++;
						counter14++;
						num1[3]=0;
					}
					if(number>=10 && num9>=0 && counter14==0 && counter15==0){
						num10=num3*10;
						num3=num10+num9;

						if(counter18==0){
							if(num3>number){
								flag5=0;
								cout<<"Please,pay attention to the number you entered"<<endl;
								counter13++;
							}}}
					if(number<10 && num9>=0 && counter14==0 && counter15==0){
						num10=num3*10;
						num3=num10+num9;
						
						if(counter18==0){
							if(num3>number){
								flag5=0;
								cout<<"Please,pay attention to the number you entered"<<endl;
								counter13++;
							}}}
					if(cntr1==0 && cntr2==0 && counter13==0){
						flag5=0;
					}
				}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*  the process that I do to prevent the user from entering numbers instead of letters 
	or letters instead of numbers when entering the coordinates*/				
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////			
				if (!(num1) && counter13==0){
					cout <<endl<<"Please enter letters only."<<endl;
					cin.clear();
					cin.ignore(100,'\n');
				}
				if (!(num3) && counter13==0){
					cout <<endl<<"Please enter numbers only."<<endl;
					cin.clear();
					cin.ignore(100,'\n');
				}
	/////////////*The operation I do to prevent the user from entering a coordinate in a previously entered coordinate.*//////		
				for(int p=0;p<g;p++){
					if(num3==arr5[p] && number2==arr6[p] && counter13==0){
						cout<<"This location is occupied!!!"<<endl;
						counter5+=1;
						}}
				for(int p=0;p<g;p++){	
					if(num3==arr7[p] && number2==arr8[p] && counter13==0){
						cout<<"This location is occupied!!!"<<endl;
						counter6+=1;
					}}
	///////////*the action I take to prevent the user from going beyond the dimensions of the board.*/////////			
				for(int i=0;i<number;i++){
					if(num3==arr3[i]){
						counter4+=1;
					}}
				if(counter4!=1 && counter13==0){
					cout<<"Please,pay attention to the number you entered"<<endl;
				}
				y=0;
				for(int i=0;i<number;i++){
					if(num1[0]==arr4[i]){
						counter3+=1;
					}
					y++;
				}
				if(counter3!=1 && counter13==0){
					cout<<"Please,pay attention to the letter you entered"<<endl;
				}
	///////////////*If the user has entered a valid coordinate it goes into this if.*////////////////			
				if(counter4==1 && counter3==1 && counter5+counter6==0 && counter13==0){
					h1=num3;
					h2=number2;
					if(nbr==0){
						if(ctr3==0){
							HexAdapter<T> :: Cell cells;
							cells.setRow(num3);
							cells.setCell(number2);

							if(counter17%2==0){
								arr5[f]=cells.getRow();
								arr6[f]=cells.getCell();
								f++;
								hexCells[num3-1][number2].setter(1);
							}
							if(counter17%2==1){
								arr7[l]=cells.getRow();
								arr8[l]=cells.getCell();
								l++;
								hexCells[num3-1][number2].setter(2);
							}
							counter17++;
							count18=HexAdapter<T>::numberofMoves(f,l);
							hold4=count18;
							
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
							int *arr18=score();
							cout<<"The score of User1 : "<<arr18[0]<<endl;
							cout<<"The score of User2 : "<<arr18[1]<<endl;
						}
						if(ctr3==1){
							HexAdapter<T> :: Cell cells;
							cells.setRow(num3);
							cells.setCell(number2);
							HexAdapter<T>::c=num3;
							HexAdapter<T>::d=num1[0];
							
							arr5[f]=cells.getRow();
							arr6[f]=cells.getCell();
							f++;
							
							hexCells[num3-1][number2].setter(1);
							count18=HexAdapter<T>::numberofMoves(f,f-1);
							hold4=count18;
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
							int *arr18=score();
							cout<<"The score of User : "<<arr18[0]<<endl;
							cout<<"The score of Computer : "<<arr18[1]<<endl;
						}
					}
					if(nbr==1 || nbr==2){
						if(num5!=0){
							if(ctr3==0){
								HexAdapter<T> :: Cell cells;
								cells.setRow(num3);
								cells.setCell(number2);
								if(counter17%2==0){
									arr5[f]=cells.getRow();
									arr6[f]=cells.getCell();
									f++;
									hexCells[num3-1][number2].setter(1);
								}
								if(counter17%2==1){
									arr7[l]=cells.getRow();
									arr8[l]=cells.getCell();
									l++;
									hexCells[num3-1][number2].setter(2);
								}
								count18=HexAdapter<T>::numberofMoves(f,l);
								hold4=count18;
								cout<<endl;
								cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
								int *arr18=score();
								cout<<"The score of User1 : "<<arr18[0]<<endl;
								cout<<"The score of User2 : "<<arr18[1]<<endl;
							}	
							if(ctr3==1){
								HexAdapter<T> :: Cell cells;
								cells.setRow(num3);
								cells.setCell(number2);
								HexAdapter<T>::c=num3;
								HexAdapter<T>::d=num1[0];
								
								arr5[f]=cells.getRow();
								arr6[f]=cells.getCell();
								f++;
								hexCells[num3-1][number2].setter(1);
								count18=HexAdapter<T>::numberofMoves(f,l);
								hold4=count18;
								
								cout<<endl;
								cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
								int *arr18=score();
								cout<<"The score of User : "<<arr18[0]<<endl;
								cout<<"The score of Computer : "<<arr18[1]<<endl;
							}
							counter17++;
						}}
					if(nbr==1 || nbr==2){
						if(num5==0){	
							for(int i=0;i<f;i++){
								x=arr5[i]-1;
								d=arr6[i];
								
								hexCells[x][d].setter(1);
							}
							for(int i=0;i<l;i++){
								z=arr7[i]-1;
								k=arr8[i];
								
								hexCells[z][k].setter(2);
							}
							if(ctr3==0){
								HexAdapter<T> :: Cell cells2;
								cells2.setRow(num3);
								cells2.setCell(number2);
								
								if(counter17%2==0){
									arr5[f]=cells2.getRow();
									arr6[f]=cells2.getCell();
									f++;

									hexCells[num3-1][number2].setter(1);
								}
								if(counter17%2==1){
									arr7[l]=cells2.getRow();
									arr8[l]=cells2.getCell();
									l++;

									hexCells[num3-1][number2].setter(2);
								}
								count18=HexAdapter<T>::numberofMoves(f,l);
								hold4=count18;
								cout<<endl;
								cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
								int *arr18=score();
								cout<<"The score of User1 : "<<arr18[0]<<endl;
								cout<<"The score of User2 : "<<arr18[1]<<endl;
							}
							if(ctr3==1){
								HexAdapter<T> :: Cell cells;
								cells.setRow(num3);
								cells.setCell(number2);
								HexAdapter<T>::c=num3;
								HexAdapter<T>::d=num1[0];
								
								arr5[f]=cells.getRow();
								arr6[f]=cells.getCell();
								f++;
								hexCells[num3-1][number2].setter(1);
								
								count18=HexAdapter<T>::numberofMoves(f,l);
								hold4=count18;
								
								cout<<endl;
								cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
								int *arr18=score();
								cout<<"The score of User : "<<arr18[0]<<endl;
								cout<<"The score of Computer : "<<arr18[1]<<endl;
							}
							
							num6++;
							counter17++;
						}}
					num5++;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*The end of game for user1 is determined as follows.
	If the user puts at least one X on each line, 
	he wins the game because he will connect the Upper and Lower X corners with the X coordinates he entered.   
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////								
					print();
					int counter=0,counter2=0;
					bool x3=isEnd(ctr3);
					
					if(x3==true){
						if(ctr3==0){
							counter17--;
							if(counter17%2==0){	
								cout<<"User1 is won"<<endl;
								flag2=0;
								flag3=0;
								counter=1;
								f=0;
								l=0;
								counter17=0;
								if(hold3==1){
									HexAdapter<T>::hold2=HexAdapter<T>::hold4;
									if(hold1==hold2){
										number2=18;
									}
								}	
								if(hold3==0){
									hold1=HexAdapter<T>::hold4;
									hold4=0;
									hold3++;
								}
								hold5++;
							}
							if(counter17%2==1){		
								cout<<"User2 is won"<<endl;
								flag2=0;
								flag3=0;
								counter=1;
								f=0;
								l=0;
								counter17=0;
								if(hold3==1){
									HexAdapter<T>::hold2=HexAdapter<T>::hold4;
									if(hold1==hold2){
										number2=18;
									}
								}		
								if(hold3==0){
									hold1=HexAdapter<T>::hold4;
									hold4=0;
									hold3++;
								}
								hold5++;
							}
						}	
					}
					if(ctr3==1){
						if(x3==true){
							cout<<"User is won"<<endl;
							flag2=0;
							flag3=0;
							counter=1;
							f=0;
							l=0;
							counter17=0;
							if(hold3==1){
								HexAdapter<T>::hold2=HexAdapter<T>::hold4;
								if(hold1==hold2){
									number2=18;
								}
							}	
							if(hold3==0){
								hold1=HexAdapter<T>::hold4;
								hold4=0;
								hold3++;
							}
							hold5++;
						}
					}		
					flag3=0;
					t=number+1;
					if(ctr3==1 && counter==0){
						
						HexAdapter<T>::Cell cells4;
						cells4=play();
						
						arr7[l]=cells4.getRow();
						arr8[l]=cells4.getCell();
						l++;
						int n1=0,n2=0;
						n1=cells4.getRow();
						n2=cells4.getCell();
						hexCells[n1-1][n2].setter(2);
						
						HexAdapter<T>::Cell cells7;
						/*With the operator () function, I press the moves made by the computer to the screen.*/
						try{
							cells7=HexAdapter<T>::operator()(n1,n2);
							cout<<arr4[cells7.getCell()]<<cells7.getRow()<<endl;
						}
						catch(OperatorMistake obj){
							cout<<obj.mistake<<endl;
						}
						print();
						
						count18=HexAdapter<T>::numberofMoves(f,l);
						hold4=count18;
						cout<<endl;
						cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
						
						int *arr18=score();
						cout<<"The score of User : "<<arr18[0]<<endl;
						cout<<"The score of Computer : "<<arr18[1]<<endl;
						
						bool x4=isEnd(ctr3);
						

						if(x4==true){
							cout<<endl<<"Computer is won"<<endl;
							flag2=0;
							flag3=0;
							f=0;
							l=0;
							counter17=0;
							if(hold3==1){
								HexAdapter<T>::hold2=HexAdapter<T>::hold4;
								if(hold1==hold2){
									number2=18;
								}
							}	
							if(hold3==0){
								hold1=HexAdapter<T>::hold4;
								hold4=0;
								hold3++;
							}
							
							hold5++;
						}
					}}
				g++;
			}}}		
}	