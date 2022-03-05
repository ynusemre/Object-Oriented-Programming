//YunusEmreGeyik-1801042635
#include "HM3.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace  std;
/*A constructor of the Hex class*/
Hex::Hex(){
	number=0;
}
/*A constructor of the Hex class*/
Hex::Hex(int arr5[100],int arr6[100],int arr7[100],int arr8[100]){
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
	}}
int Hex::a=0;
int Hex::b=0;
int Hex::c=0;
int Hex::d=0;
int Hex::hold1=0;
int Hex::hold2=0;
int Hex::hold3=0;
int Hex::hold4=0;
int Hex::hold5=0;
/*A constructor of the nested Cell class*/
Hex::Cell::Cell(){
	cell=0;
	row=0;
}
/*gets the letter in the column from the user*/
void Hex::Cell::setCell(int Newcell){
	cell=Newcell;
}
/*getting the number in the line from the user*/
void Hex::Cell::setRow(int Newrow){
	row=Newrow;
}
/*returns the letter in the column*/
int Hex::Cell::getCell()const{
	return cell;
}
/*returning the number on the line*/
int Hex::Cell::getRow()const{
	return row;
}
/*Thanks to this function, I assign values to the coordinates of our vector, which is cell type.*/
/*I assigned 1 to places with X, 2 to places with 0, and 0 to places with dots.*/
void Hex::Cell::setter(int x){
	row=x;
	cell=x;
}
/*static function that returns the number of cells that are marked*/
int Hex::Marked(int f,int l){
	int count=f+l;
	return count;
}
/*function that returns the current width of the game board.*/
int Hex::Current_With(int x)const{
	return x;
}
/*function that returns the current height of the game board.*/
int Hex::Current_height(int y)const{
	return y;
}
/*The function that compares the game of the first opened object with the game of the second opened object.
for the their marked cell number.Returns true if the first game is too much.*/
bool Hex::compare(Hex object){
	if(hold3==0){
		hold1=Hex::Marked(hold4,hold5);
	}
	if(hold3==1){
		hold2=Hex::Marked(hold4,hold5);
	}
	if(hold1>hold2){
		return true;
	}
	return false;
}
/*I call the inline function in a for loop while printing the last state of the board.
It helps to print the board using the vector and enum structure.*/
inline void Hex::control(int &i,int &j){
	int counter=0,counter2=0;
	CellState cell1=dot;
	CellState cell2=cross;
	CellState cell3=circle;

	if(hexCells[i][j].cell==cell2 && hexCells[i][j].row==cell2){
		cout<<" X ";
		counter++;
	}
	if(hexCells[i][j].cell==cell3 && hexCells[i][j].row==cell3){
		cout<<" O ";
		counter2++;
	}
	if(hexCells[i][j].cell==cell1 && hexCells[i][j].row==cell1 && counter==0 && counter2==0){
		cout<<" . ";
	}}
/*the function that prints the current state of the game board.*/	
void Hex::Current_board(){
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
/*the function that finds out which player won the game. The winner of the game is determined.*/	
int Hex::Game_End(int r){
	int counter10=0,counter11=0,counter12=0,counter13=0;
	if(r==0){
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				if(hexCells[i][j].cell==1 && hexCells[i][j].row==1){
					counter10++;
					break;
				}}}
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){		
				if(hexCells[j][i].cell==2 && hexCells[j][i].row==2){
					counter11++;
					break;
				}}}		
		if(counter10==number){
			return 1;
		}
		if(counter11==number){
			return 2;
		}}
	if(r==1){
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				if(hexCells[i][j].cell==1 && hexCells[i][j].row==1){
					counter12++;
					break;
				}}}
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){		
				if(hexCells[j][i].cell==2 && hexCells[j][i].row==2){
					counter13++;
					break;
				}}}		
		if(counter12==number){
			return 3;
		}
		if(counter13==number){
			return 4;
		}}
	return 0;	
}
/*The function where I take the size of the game board from the user, 
press the first version of the board on the screen and ask the user how they want to play the game.*/
void Hex::playGame(int &option){
	int number4=0;
	int counter=0,counter2=0;
	
	while(true){
		counter=0;
		cout<<"Plaese enter size of board(line X column)(6x6,7x7, 8x8, 9x9, 10x10, 11x11 or 12x12):"<<endl;
		
		cout<<"Line:";
		cin>>number;
				
		cout<<"Column:";
		cin>>number4;
		 
		if(number>=5 && number4>=5 && number==number4){
			//Hex::number=number;
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
	char arr[7]="O SIDE";
	int t=number+1;

	for(int i=0;i<number;i++){
		if(i==0){
			cout<<"--------------X SIDE--------------"<<endl;
			cout<<"     ";
				
			for(char i=65;i<65+number;i++){
				cout<<i<<"  ";
			}
			cout<<endl;
		}
		if(i<6){
			cout<<arr[i]<<"   ";
			cout<<i+1;
		}
		if(i>=6){
			cout<<"    "<<i+1;
		}
		for(int k=0;k<i;k++){
			cout<<"  ";
		}
		for(int j=0;j<number;j++){
			cout<<" . ";
			if(j==number-1){
				for(;t>0;t--){
					cout<<"  ";
				}
				if(i<6){
					cout<<arr[i];
					t=number-i;
				}}}
		if(i==number-1){
			cout<<endl;
			cout<<"--------------X SIDE--------------"<<endl;
		}
		cout<<endl;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////	
	while(true){
		cout<<endl;
		cout<<"How do you want to play?"<<endl;
		cout<<"1.(User X User)"<<endl;
		cout<<"2.(User X Computer)"<<endl;
				
		cout<<"Please select an option:";
		cin>>option;
		
		if(option==1 || option==2){
			break;
		}
		if(option!=1 && option!=2){
			cout<<endl<<"Please choose right option."<<endl;
		}
		if (!(option)){
			cout <<endl<<"Please enter numbers only."<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}}}

/*Whichever user last used save and load commands, it is his turn when the game is reloaded.*/


/*I am  reading it in the file.
in the first line, I read who is on the turn.if there is one the turn is user1 or user,if there is two the turn is user2 
On the second line, I read the the board size.
In the third line, I read the number of moves of user1.
In the fourth line, I read the number of moves of user2.

thanks to the fifth line, I determine who the game is playing against.if there is three the game is user1VSuser2,
if there is four the game is userVScomputer.

On the sixth line, you are reading the coordinates of user1's moves.
On the seventh line, you read the coordinates of user2's moves.
Thanks to the other lines, I print the last state of the game board on the screen.*/

void Hex::load(string file_name,int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &num,int &num2,int &f,int &l,int &who_vs_who){
	ifstream file,file2,file3;
	int number=0,number2=0;
	char str;
	string str2,str3;
	int counter=0;
	
	file.open(file_name);
	file2.open(file_name);
	file3.open(file_name);
	
	if(!file.is_open()){
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	if(!file2.is_open()){
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	if(!file3.is_open()){
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	getline(file,str2);
	getline(file,str2);
	getline(file,str2);
	getline(file,str2);
	getline(file,str2);
	getline(file,str2);
	getline(file,str2);
	
	while(getline(file,str2)){    //I press the game board in the file.
		cout<<str2<<endl;
	}
	int num3=0,num4=0,num5=0,num6=0,num7=0;
	
	file2>>str;
	num=(int)str-48; //I determine who wins the game. If the number read is 1, then the turn is user1, if the number read is 2, then the turn is user2.
	file2>>str;
	num2=(int)str-48; //I'm reading the size of the game board.
	
	/*I adjusted my code according to the different situations of the game board.*/
	
	/*I had to do such a long process for different situations of the game board :D*/

	if(num2==1){
		file2>>str;
		num7=(int)str-48;
		if(num7==0){
			num2=10;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==1){
			num2=11;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==2){
			num2=12;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==3){
			num2=13;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==4){
			num2=14;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==5){
			num2=15;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==6){
			num2=16;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==7){
			num2=17;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==8){
			num2=18;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==9){
			num2=19;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}}
	if(num2==2){	
		file2>>str;
		num7=(int)str-48;
		if(num7==0 ){
			num2=20;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==1){
			num2=21;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==2){
			num2=22;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==3){
			num2=23;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==4){
			num2=24;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==5){
			num2=25;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==6){
			num2=26;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==7){
			num2=27;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==8){
			num2=28;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}
		if(num7==9){
			num2=29;
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
		}}	
	if(num2<10){
		file2>>str;
		f=(int)str-48;
		file2>>str;
		l=(int)str-48;
		file2>>str;
		who_vs_who=(int)str-48;
	}
	getline(file3,str3);
	getline(file3,str3);
	getline(file3,str3);
	getline(file3,str3);
	getline(file3,str3);
	getline(file3,str3);

	/*I get the coordinates of the players from the file.*/
	
/*I had to do such a long process for different situations of the game board :D*/

	if(num2>=10){
		for(int i=0;i<100;i++){
			if(str3[i]==':'){
				break;
			}
			if(i==0){
				num3=(int)str3[i]-48;
				num4=(int)str3[i+1]-48;
				
				if(num3==1){
					if(num4==0){
						num3=10;
					}
					if(num4==1){
						num3=11;
					}
					if(num4==2){
						num3=12;
					}
					if(num4==3){
						num3=13;
					}
					if(num4==4){
						num3=14;
					}
					if(num4==5){
						num3=15;
					}
					if(num4==6){
						num3=16;
					}
					if(num4==7){
						num3=17;
					}
					if(num4==8){
						num3=18;
					}
					if(num4==9){
						num3=19;
					}
				}
				if(num3==2){
					if(num4==0){
						num3=20;
					}
					if(num4==1){
						num3=21;
					}
					if(num4==2){
						num3=22;
					}
					if(num4==3){
						num3=23;
					}
					if(num4==4){
						num3=24;
					}
					if(num4==5){
						num3=25;
					}
					if(num4==6){
						num3=26;
					}
					if(num4==7){
						num3=27;
					}
					if(num4==8){
						num3=28;
					}
					if(num4==9){
						num3=29;
					}}
				arr5[number]=num3;
				number++;
			}
			if(str3[i]==','){
				num5=(int)str3[i+1]-48;
				num6=(int)str3[i+2]-48;

				if(num5==1){
					if(num6==0){
						num5=10;
					}
					if(num6==1){
						num5=11;
					}
					if(num6==2){
						num5=12;
					}
					if(num6==3){
						num5=13;
					}
					if(num6==4){
						num5=14;
					}
					if(num6==5){
						num5=15;
					}
					if(num6==6){
						num5=16;
					}
					if(num6==7){
						num5=17;
					}
					if(num6==8){
						num5=18;
					}
					if(num6==9){
						num5=19;
					}}
				if(num5==2){
					if(num6==0){
						num5=20;
					}
					if(num6==1){
						num5=21;
					}
					if(num6==2){
						num5=22;
					}
					if(num6==3){
						num5=23;
					}
					if(num6==4){
						num5=24;
					}
					if(num6==5){
						num5=25;
					}
					if(num6==6){
						num5=26;
					}
					if(num6==7){
						num5=27;
					}
					if(num6==8){
						num5=28;
					}
					if(num6==9){
						num5=29;
					}}
				arr6[number2]=num5;
				number2++;
			}
			if(str3[i]=='.'){
				num3=(int)str3[i+1]-48;
				num4=(int)str3[i+2]-48;

				if(num3==1){
					if(num4==0){
						num3=10;
					}
					if(num4==1){
						num3=11;
					}
					if(num4==2){
						num3=12;
					}
					if(num4==3){
						num3=13;
					}
					if(num4==4){
						num3=14;
					}
					if(num4==5){
						num3=15;
					}
					if(num4==6){
						num3=16;
					}
					if(num4==7){
						num3=17;
					}
					if(num4==8){
						num3=18;
					}
					if(num4==9){
						num3=19;
					}}
				if(num3==2){
					if(num4==0){
						num3=20;
					}
					if(num4==1){
						num3=21;
					}
					if(num4==2){
						num3=22;
					}
					if(num4==3){
						num3=23;
					}
					if(num4==4){
						num3=24;
					}
					if(num4==5){
						num3=25;
					}
					if(num4==6){
						num3=26;
					}
					if(num4==7){
						num3=27;
					}
					if(num4==8){
						num3=28;
					}
					if(num4==9){
						num3=29;
					}}
				arr5[number]=num3;
				number++;
			}}
		num3=0,num4=0,num5=0,num6=0;
		number2=0;
		number=0;
		getline(file3,str3);

		for(int i=0;i<100;i++){
			if(str3[i]==':'){
				break;
			}
			if(i==0){
				num3=(int)str3[i]-48;
				num4=(int)str3[i+1]-48;
				
				if(num3==1){
					if(num4==0){
						num3=10;
					}
					if(num4==1){
						num3=11;
					}
					if(num4==2){
						num3=12;
					}
					if(num4==3){
						num3=13;
					}
					if(num4==4){
						num3=14;
					}
					if(num4==5){
						num3=15;
					}
					if(num4==6){
						num3=16;
					}
					if(num4==7){
						num3=17;
					}
					if(num4==8){
						num3=18;
					}
					if(num4==9){
						num3=19;
					}}
				if(num3==2){
					if(num4==0){
						num3=20;
					}
					if(num4==1){
						num3=21;
					}
					if(num4==2){
						num3=22;
					}
					if(num4==3){
						num3=23;
					}
					if(num4==4){
						num3=24;
					}
					if(num4==5){
						num3=25;
					}
					if(num4==6){
						num3=26;
					}
					if(num4==7){
						num3=27;
					}
					if(num4==8){
						num3=28;
					}
					if(num4==9){
						num3=29;
					}}
				arr7[number]=num3;
				number++;
			}
			if(str3[i]==','){
				num5=(int)str3[i+1]-48;
				num6=(int)str3[i+2]-48;

				if(num5==1){
					if(num6==0){
						num5=10;
					}
					if(num6==1){
						num5=11;
					}
					if(num6==2){
						num5=12;
					}
					if(num6==3){
						num5=13;
					}
					if(num6==4){
						num5=14;
					}
					if(num6==5){
						num5=15;
					}
					if(num6==6){
						num5=16;
					}
					if(num6==7){
						num5=17;
					}
					if(num6==8){
						num5=18;
					}
					if(num6==9){
						num5=19;
					}}
				if(num5==2){
					if(num6==0){
						num5=20;
					}
					if(num6==1){
						num5=21;
					}
					if(num6==2){
						num5=22;
					}
					if(num6==3){
						num5=23;
					}
					if(num6==4){
						num5=24;
					}
					if(num6==5){
						num5=25;
					}
					if(num6==6){
						num5=26;
					}
					if(num6==7){
						num5=27;
					}
					if(num6==8){
						num5=28;
					}
					if(num6==9){
						num5=29;
					}
				}
				arr8[number2]=num5;
				number2++;
			}
			if(str3[i]=='.'){
				num3=(int)str3[i+1]-48;
				num4=(int)str3[i+2]-48;

				if(num3==1){
					if(num4==0){
						num3=10;
					}
					if(num4==1){
						num3=11;
					}
					if(num4==2){
						num3=12;
					}
					if(num4==3){
						num3=13;
					}
					if(num4==4){
						num3=14;
					}
					if(num4==5){
						num3=15;
					}
					if(num4==6){
						num3=16;
					}
					if(num4==7){
						num3=17;
					}
					if(num4==8){
						num3=18;
					}
					if(num4==9){
						num3=19;
					}
				}
				if(num3==2){
					if(num4==0){
						num3=20;
					}
					if(num4==1){
						num3=21;
					}
					if(num4==2){
						num3=22;
					}
					if(num4==3){
						num3=23;
					}
					if(num4==4){
						num3=24;
					}
					if(num4==5){
						num3=25;
					}
					if(num4==6){
						num3=26;
					}
					if(num4==7){
						num3=27;
					}
					if(num4==8){
						num3=28;
					}
					if(num4==9){
						num3=29;
					}
				}
				arr7[number]=num3;
				number++;
			}}}

	if(num2<10){
		for(int i=0;i<100;i++){
			if(str3[i]==':'){
				break;
			}
			
			if(i%2==0){
				arr5[number]=(int)str3[i]-48;
				number++;
				
			}
			if(i%2==1){
				arr6[number2]=(int)str3[i]-48;
				number2++;
			}}
		number2=0;
		number=0;
		getline(file3,str3);
		for(int i=0;i<100;i++){
			if(str3[i]==':'){
				break;
			}
			if(i%2==0){
				arr7[number]=(int)str3[i]-48;
				number++;
				
			}
			if(i%2==1){
				arr8[number2]=(int)str3[i]-48;
				number2++;
			}}}
	file.close();
	file2.close();
	file3.close();
}
/*I got the file name
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
Thanks to the other lines, I am saving the last state of the game board on the screen.
*/
void Hex::save(string file_name,char arr[7],int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &number,int f,int l,int wch_user,int who_vs_who){
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

			if(hexCells[i][j].cell==cell2 && hexCells[i][j].row==cell2){
				file<<" X ";
				counter++;
			}
							
			if(hexCells[i][j].cell==cell3 && hexCells[i][j].row==cell3){
				file<<" O ";
				counter2++;
			}

			if(hexCells[i][j].cell==cell1 && hexCells[i][j].row==cell1 && counter==0 && counter2==0){
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

//for Computer
/*The computer randomly puts its moves in 6 directions around the coordinates entered by the user. 
If the user puts X in a coordinate which has full 6 directions on the game board, 
then the computer puts another part of the board that is currently empty.
I used vector as an extra in this assignment.*/		
void Hex::play(){
	int counter8=0;
	char arr[7]="O SIDE";
	int z=0,k=0;
	char num2;
	int num3=0,flag4=1,m=0,flag2=1,flag=1,counter7=0,y=0,t=0,l=0;
	int arr3[100];
	char arr4[100];
	int number3=0,num4=0;
	char num1[15];
	CellState cell1=dot;
	CellState cell2=cross;
	CellState cell3=circle;

	for(int i=0;i<number;i++){
		arr3[i]=i+1;
	}
	for(int i=65;i<65+number;i++){
		arr4[y]=i;
		y++;
	}
	num3=Hex::c;
	num1[0]=Hex::d;
	
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
			Hex :: Cell cells3;
			cells3.setRow(num4);
			cells3.setCell(number3);

			arr7[a]=cells3.row;
			arr8[a]=cells3.cell;
			
			cout<<num2<<num4<<endl;
			hexCells[num4-1][number3].setter(2);
			
			int counter=0,counter2=0;
			flag4=0;
			t=number+1;
						
			Current_board();
			a++;
		}
		b++;
	}}

//for User
/*the function I created for the moves made by the users.*/	
void Hex::play(int number2,int num3){
	int counter10=0,counter11=0,counter12=0;
	char arr[7]="O SIDE";
	
	char num1[15];
	int num4=0,num5=0,num6=0,num9=0,num10=0,num11=0;
	int g=0,m=0;
	int x=0,d=0,z=0,k=0;
	int ctr1=0,ctr2=0;
	int nbr=0,nbr2=0;
	int ctr3=0;
	int x2=0;
	if(number2==0){
		ctr3=0;
	}
	if(number2==1){
		ctr3=1;
	}
	
	int arr3[100];
	char arr4[100];
	int f=0,l=0;

	int number3=0,y=0,num7=0,t=0;
	
	int counter17=0;

	CellState cell1=dot;
	CellState cell2=cross;
	CellState cell3=circle;
	
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
	int who_vs_who=0;
	int flag2=1;
	
	g=f;
	m=l;
	
	while(flag2!=0){
		int flag3=1,flag4=1;
////////////////////////////////////////////(USER)/////////////////////////////////////////////////////////////////  			
		while(flag3!=0 && ctr1==1){
			int counter3=0,counter4=0,counter5=0,counter6=0,counter10=0,counter13=0,counter14=0,counter15=0,counter16=0;
			num9=0,num10=0,num11=-1;
			auto flag5=flag3;
//////////*I want the coordinates for X from the first user.*////////////	
			char file_name[20];
			while(flag5!=0){
			/*I write the user that she can use the SAVE and LOAD commands if they want.*/
				cout<<endl<<"!!!Please write SAVE or LOAD for save or load the current game status!!!"<<endl;
				if(ctr3==1){
					cout<<"USER(X)=";
				}
				if(ctr3==0){
					if(counter17%2==0){
						cout<<"USER1(X)=";
					}
					if(counter17%2==1){
						cout<<"USER2(O)=";
					}
				}
				cin>>num1;
				int cntr1=0,cntr2=0;
				counter13=0;
				
				number2=(int)num1[0]-65;
				num3=(int)num1[1]-48;
				num9=(int)num1[2]-48;
				num11=(int)num1[3]-48;
				/*If the user has entered the SAVE command, 
				I am saving the last image of the game and the latest information of the game.*/
				if(num1[0]=='S' && num1[1]=='A' && num1[2]=='V' && num1[3]=='E'){
					
					cin>>file_name;	
					
					if(ctr3==0){
						if(counter17%2==0){
							save(file_name,arr,arr5,arr6,arr7,arr8,number,f,l,1,3);
						}
						if(counter17%2==1){
							save(file_name,arr,arr5,arr6,arr7,arr8,number,f,l,2,3);
						}
					}
					if(ctr3==1){

						l=Hex::a;
						save(file_name,arr,arr5,arr6,arr7,arr8,number,f,l,1,4);
					}	
					cntr1=1;
					counter15++;
				}
				/*If the user uses the LOAD command, the final state of the game in the entered file name is printed on the screen. 
				And  game is continued  with The that game.*/
				if(num1[0]=='L' && num1[1]=='O' && num1[2]=='A' && num1[3]=='D'){
					
					cin>>file_name;
								
					int num8=0;
					
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
					
					load(file_name,arr5,arr6,arr7,arr8,num7,num8,f,l,who_vs_who);
					number=num8;
					f=f;
					l=l;

					int x1=Current_With(num8);
					int x2=Current_height(num8);
					cout<<endl<<"The current width:"<<x1<<endl;
					cout<<"The current height:"<<x2<<endl;
					
					/*I press the number of cells marked on the game board to the screen.*/
					int count18=Hex::Marked(f,l);
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
						I switch to the User_vs_Computer game*/
					if(who_vs_who==4){
						if(num7==1 ){
							cout<<"The turn was at User."<<endl;
						}
						///////////////////////////////////////////////////h=who_vs_who;
						ctr3=1;	

						nbr=num7;
						nbr2=num8;
						
						flag5=0;
						counter13++;
						counter16++;
					}
					/*If who_vs_who 4 is coming, the status of the players is changing.
						I switch to the User_vs_User game*/
					if(who_vs_who==3){
						if(num7==1 ){
							counter17=0;
							cout<<"The turn was at User1."<<endl;
							counter13++;
							flag5=0;
							nbr=1;
						}
						if(num7==2){
							counter17=1;
							cout<<"The turn was at User2."<<endl;
							flag3=0;
							flag5=0;
							counter13++;
							nbr=2;
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
				if(num11>=0 && num11<10 && counter15==0){
					flag5=0;
					cout<<"Please,pay attention to the number you entered"<<endl;
					counter13++;
					counter14++;
				}
				if(number>=10 && num9>=0 && counter14==0 && counter15==0){
					num10=num3*10;
					num3=num10+num9;

					if(num3>number){
						flag5=0;
						cout<<"Please,pay attention to the number you entered"<<endl;
						counter13++;
					}}
				if(number<10 && num9>=0 && counter14==0 && counter15==0){
					num10=num3*10;
					num3=num10+num9;
					
					if(num3>number){
						flag5=0;
						cout<<"Please,pay attention to the number you entered"<<endl;
						counter13++;
					}}
				if(cntr1==0 && cntr2==0 && counter13==0){
					flag5=0;
				}}
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
				if(nbr==0){
					if(ctr3==0){
						Hex :: Cell cells;
						cells.setRow(num3);
						cells.setCell(number2);

						if(counter17%2==0){
							arr5[f]=cells.row;
							arr6[f]=cells.cell;
							f++;
					
							hexCells[num3-1][number2].setter(1);
						}
						if(counter17%2==1){
							arr7[l]=cells.row;
							arr8[l]=cells.cell;
							l++;
							hexCells[num3-1][number2].setter(2);
						}
						counter17++;
						int count18=Hex::Marked(f,l);
						Hex::hold4=f;
						Hex::hold5=l;
						cout<<endl;
						cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
					}
					if(ctr3==1){
						Hex :: Cell cells;
						cells.setRow(num3);
						cells.setCell(number2);
						Hex::c=num3;
						Hex::d=num1[0];
						
						arr5[f]=cells.row;
						arr6[f]=cells.cell;
						f++;
						hexCells[num3-1][number2].setter(1);
						int count18=Hex::Marked(f,f-1);
						Hex::hold4=f;
						Hex::hold5=f-1;
						cout<<endl;
						cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
					}
				}
				if(nbr==1 || nbr==2){
					if(num5!=0){
						if(ctr3==0){
							Hex :: Cell cells;
							cells.setRow(num3);
							cells.setCell(number2);
							if(counter17%2==0){
								arr5[f]=cells.row;
								arr6[f]=cells.cell;
								f++;

								hexCells[num3-1][number2].setter(1);
							}
							if(counter17%2==1){
								arr7[l]=cells.row;
								arr8[l]=cells.cell;
								l++;

								hexCells[num3-1][number2].setter(2);
							}
							int count18=Hex::Marked(f,l);
							Hex::hold4=f;
							Hex::hold5=l;
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
						}	
						if(ctr3==1){
							Hex :: Cell cells;
							cells.setRow(num3);
							cells.setCell(number2);
							Hex::c=num3;
							Hex::d=num1[0];
							
							arr5[f]=cells.row;
							arr6[f]=cells.cell;
							f++;
							hexCells[num3-1][number2].setter(1);
							int count18=Hex::Marked(f,l);
							Hex::hold4=f;
							Hex::hold5=l;
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
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
							Hex :: Cell cells2;
							cells2.setRow(num3);
							cells2.setCell(number2);
							
							if(counter17%2==0){
								arr5[f]=cells2.row;
								arr6[f]=cells2.cell;
								f++;

								hexCells[num3-1][number2].setter(1);
							}
							if(counter17%2==1){
								arr7[l]=cells2.row;
								arr8[l]=cells2.cell;
								l++;

								hexCells[num3-1][number2].setter(2);
							}
							int count18=Hex::Marked(f,l);
							Hex::hold4=f;
							Hex::hold5=l;
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
						}
						if(ctr3==1){
							Hex :: Cell cells;
							cells.setRow(num3);
							cells.setCell(number2);
							Hex::c=num3;
							Hex::d=num1[0];
							
							arr5[f]=cells.row;
							arr6[f]=cells.cell;
							f++;
							int count18=Hex::Marked(f,l);
							Hex::hold4=f;
							Hex::hold5=l;
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
							hexCells[num3-1][number2].setter(1);

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
				Current_board();
				int counter=0,counter2=0;
				
				int x3=Game_End(ctr3);

				if(x3==1){
					cout<<"User1 is won"<<endl;
					flag2=0;
					flag3=0;
					counter=1;
				}
				if(x3==2){
					cout<<"User2 is won"<<endl;
					flag2=0;
					flag3=0;
					counter=1;
				}
				if(x3==3){
					cout<<"User is won"<<endl;
					flag2=0;
					flag3=0;
					counter=1;
				}
				
				flag3=0;
				t=number+1;
							
				if(ctr3==1 && counter==0){
					play();
					
					x2++;
					int count18=Hex::Marked(f,x2);
					Hex::hold4=f;
					Hex::hold5=x2;
					cout<<endl;
					cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;

					int x4=Game_End(ctr3);
					if(x4==4){
						cout<<endl<<"Computer is won"<<endl;
						flag2=0;
						flag3=0;
						
					}}}
			g++;
		}}}
void Hex::menu(){
	int number=0;
	int num7=0,num8=0;
	int flag=1;
	int y=0,h=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	(Accurate board size control)	
	int t=0;
	int option=0;
	int number2=0,num3=0;

	playGame(option);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (User1(X) vs. User2(O))			
		if(option==1){
			cout<<endl;
			play(number2,num3);
		}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (User vs computer)					
		else if(option==2){
			cout<<endl;
				
			number2=1;
			play(number2,num3);
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////				
		else{
			cerr<<endl<<"invalid option."<<endl;
			cerr<<"Please select again."<<endl;
		}
}