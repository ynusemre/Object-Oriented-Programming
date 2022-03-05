//YunusEmreGeyik-1801042635
#include "HM4.h"
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace  std;
//Arrays where I keep coordinates
int *Hex::arr5=nullptr;
int *Hex::arr6=nullptr;
int *Hex::arr7=nullptr;
int *Hex::arr8=nullptr;
char *Hex::arr=nullptr;

/*A constructor of the Hex class*/
Hex::Hex(const int &x1,const int &x2):number(x1),hold5(x1),number_marked(x1),size(x2){
	arr5=new int[size];    //array sizes are determined according to size
	arr6=new int[size];
	arr7=new int[size];
	arr8=new int[size];
	arr=new char[7];
	
	char arr2[7]="O SIDE";

	for(int i=0;i<7;i++){
		arr[i]=arr2[i];
	}	
	for(int i=0;i<size;i++){
		arr5[i]=0;
	}
	for(int i=0;i<size;i++){
		arr6[i]=0;
	}
	for(int i=0;i<size;i++){
		arr7[i]=0;
	}
	for(int i=0;i<size;i++){
		arr8[i]=0;
	}}

Hex::Hex(const Hex &object){    //Copy Constructor
	this->number=object.number;
	this->number_marked=object.number_marked;
	this->hold5=object.hold5;
	this->size=object.size;
	
	arr5=new int[this->size+1];
	arr6=new int[this->size+1];
	arr7=new int[this->size+1];
	arr8=new int[this->size+1];
	arr=new char[7];

	arr5=object.arr5;
	arr6=object.arr6;
	arr7=object.arr7;
	arr8=object.arr8;
	arr=object.arr;
	
	hexCells=new Cell*[this->number];
	for(int i=0;i<this->number;i++){
		hexCells[i]=new Cell[this->number];
	}
	hexCells=object.hexCells;
}
//Copy Assignment Operator
Hex& Hex::operator=(const Hex &object){ 
	if(this == &object){
		return *this;
	}
	else{
		delete []arr5;
		delete []arr6;
		delete []arr7;
		delete []arr8;
		delete []arr;

		delete []*hexCells;

		this->number=object.number;
		this->number_marked=object.number_marked;
		this->hold5=object.hold5;
		this->size=object.size;
		
		arr5=new int[this->size+1];
		arr6=new int[this->size+1];
		arr7=new int[this->size+1];
		arr8=new int[this->size+1];
		arr=new char[7];

		arr5=object.arr5;
		arr6=object.arr6;
		arr7=object.arr7;
		arr8=object.arr8;
		arr=object.arr;

		hexCells=new Cell*[this->number];
		for(int i=0;i<this->number;i++){
			hexCells[i]=new Cell[this->number];
		}
		hexCells=object.hexCells;

		return *this;
	}	
}
//My static variables
int Hex::b=0;
int Hex::c=0;
int Hex::d=0;
int Hex::f=0;
int Hex::l=0;
int Hex::e=0;
int Hex::ctr3=0;
int Hex::ctr4=0;
int Hex::ctr5=0;
int Hex::counter17=0;
int Hex::hold1=0;
int Hex::hold2=0;
int Hex::hold3=0;
int Hex::hold4=0;
int Hex::wch_user=0;
int Hex::who_vs_who=0;
int Hex::num=0;
int Hex::num2=0;
int Hex::count18=0;

Hex::~Hex(){  //Destructor for the Hex class
	if(hold5!=0){
		if(ctr4==0){
			delete []arr5;
			delete []arr6;
			delete []arr7;
			delete []arr8;
			delete []arr;

			ctr4++;
		}	
		delete []*hexCells;
	}}
/*gets a number from the user for the size of board*/	
void Hex::setNumber(const int &number){  
	this->number=number;
}
//returns the size of boar
int Hex::getNumber () const{
	return this->number;
}
/*gets a number from the user for the size of hold5 variable
i am using this variable for the compere processes*/
int Hex::getHold5 () const{
	return this->hold5;
}
/*gets a number from the user for the size of array*/
void Hex::setHold5(const int &hold5){
	this->hold5=hold5;
}
/*returns the size of array*/
int Hex::getSize () const{
	return this->size;
}
/*gets a number from the user for the size of array*/
void Hex::setSize(const int &size){
	this->size=size;
}
/*gets a number from the user for the number_of_marked*/
void Hex::setNumber_Marked(const int &number_marked){
	this->number_marked=number_marked;
}
/*returns the number_of_marked*/
int Hex::getNumber_Marked () const{
	return this->number_marked;
}
/*gets the letter in the column from the user*/
void Hex::Cell::setCell(const int &cell){
	this->cell=cell;
}
/*getting the number in the line from the user*/
void Hex::Cell::setRow(const int &row){
	this->row=row;
}
/*returns the letter in the column*/
int Hex::Cell::getCell()const{
	return this->cell;
}
/*returning the number on the line*/
int Hex::Cell::getRow()const{
	return this->row;
}
/*Thanks to this function, I assign values to the coordinates of our vector, which is cell type.*/
/*I assigned 1 to places with X, 2 to places with 0, and 0 to places with dots.*/
void Hex::Cell::setter(const int &x){
	this->row=x;
	this->cell=x;
}
/*static function that returns the number of cells that are marked*/
int Hex::Marked(const int &f,const int &l){
	int count=f+l;
	return count;
}
/*function that returns the current width of the game board.*/
int Hex::Current_With(const int &x)const{
	return x;
}
/*function that returns the current height of the game board.*/
int Hex::Current_height(const int &y)const{
	return y;
}
/*The operator that compares the game of the first opened object with the game of the second opened object.
for the their marked cell number.Returns true if the first game is too much.*/
bool Hex::operator==(Hex &object)const{
	object.setNumber_Marked(hold1);
	hold1=object.getNumber_Marked();
	
	if(hold1>hold2){
		return true;
	}
	return false;
}
/*the function that finds out which player won the game. The winner of the game is determined.*/
int Hex::Game_End(const int &r)const{
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
			return 1;
		}
		if(counter11==number){
			return 2;
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
			return 3;
		}
		if(counter13==number){
			return 4;
		}}
	return 0;	
}
/*I call the inline function in a for loop while printing the last state of the board.
It helps to print the board using the vector and enum structure.*/
inline void Hex::control(const int &i,const int &j)const{
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
/*the operator that prints the current state of the game board.*/		
ostream &operator <<(ostream &out, const Hex &obj){
	int k=0,t=0;
	t=obj.number+1;

	int counter=0,counter2=0;
	CellState cell1=dot;
	CellState cell2=cross;
	CellState cell3=circle;
	
	for(int i=0;i<obj.number;i++){
		if(i==0){
			out<<"-----------X SIDE-----------"<<endl;
			out<<"     ";
									
			for(char i=65;i<65+obj.number;i++){
				out<<i<<"  ";
			}
			out<<endl;
		}
		if(i<6){
			out<<obj.arr[i]<<"  ";
			out<<i+1;
		}
		if(i>=6){
			out<<"   "<<i+1;
		}
		for(int k=0;k<i;k++){
			out<<"  ";
		}
		for(int j=0;j<obj.number;j++){
			counter=0,counter2=0;
			if(obj.hexCells[i][j].getCell()==cell2 && obj.hexCells[i][j].getRow()==cell2){
				out<<" X ";
				counter++;
			}
			if(obj.hexCells[i][j].getCell()==cell3 && obj.hexCells[i][j].getRow()==cell3){
				out<<" O ";
				counter2++;
			}
			if(obj.hexCells[i][j].getCell()==cell1 && obj.hexCells[i][j].getRow()==cell1 && counter==0 && counter2==0){
				out<<" . ";
			}}
			
		for(int j=0;j<obj.number;j++){
			if(j==obj.number-1){
				for(;t>0;t--){
					out<<"  ";
				}
				if(i<6){
					out<<obj.arr[i];
				}
				t=obj.number-i;
			}}
		if(i==obj.number-1){
			out<<endl;
			out<<"-----------X SIDE-----------"<<endl;
		}
		out<<endl;
	}
	return out;
}

//calling ostream 
void Hex::Current_board()const{
	cout<<*this;
}
//My PRE UNDO OPERATOR
/*it takes the moves one step back.
For userXuser;
If user1 uses the undo operator, user2's last move is deleted and the sequence passes to user2.
For userXcomputer;
If he uses the user undo operator, the last move of the user and the computer will be deleted and user will be back again. */
void Hex::operator--(){
	setNumber(e);
	int a1=0,a2=0,b1=0,b2=0;
	
	if(ctr3==0){
		hexCells=new Cell*[number];
		for(int i=0;i<number;i++){
			hexCells[i]=new Cell[number];
		}
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				hexCells[i][j].setter(0);
			}}
		if(counter17%2==0){
			for(int i=0;i<l-1;i++){
				b1=arr7[i];
				b2=arr8[i];
				hexCells[b1-1][b2].setter(2);
			}
			arr7[l-1]=0;
			arr8[l-1]=0;
			l--;
			for(int i=0;i<f;i++){
				a1=arr5[i];
				a2=arr6[i];
				hexCells[a1-1][a2].setter(1);
			}}
		if(counter17%2==1){
			for(int i=0;i<f-1;i++){
				a1=arr5[i];
				a2=arr6[i];
				hexCells[a1-1][a2].setter(1);
			}
			arr5[f-1]=0;
			arr6[f-1]=0;
			f--;
			for(int i=0;i<l;i++){
				b1=arr7[i];
				b2=arr8[i];
				hexCells[b1-1][b2].setter(2);
			}}}
	if(ctr3==1){
		hexCells=new Cell*[number];
		for(int i=0;i<number;i++){
			hexCells[i]=new Cell[number];
		}
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				hexCells[i][j].setter(0);
			}}
		a1=0,a2=0,b1=0,b2=0;
		for(int i=0;i<f-1;i++){
			a1=arr5[i];
			a2=arr6[i];
			hexCells[a1-1][a2].setter(1);
		}
		
		for(int i=0;i<l-1;i++){
			b1=arr7[i];
			b2=arr8[i];
			hexCells[b1-1][b2].setter(2);
		}	
		arr5[f-1]=0;
		arr6[f-1]=0;
		arr7[l-1]=0;
		arr8[l-1]=0;
		f--;
		l--;
	}}
//My POST UNDO OPERATOR
/*It does the same operations as the pre operator, except that it takes a parameter.*/	
void Hex::operator --(int y){
	setNumber(e);
	int a1=0,a2=0,b1=0,b2=0;
	
	if(ctr3==0){
		hexCells=new Cell*[number];
		for(int i=0;i<number;i++){
			hexCells[i]=new Cell[number];
		}
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				hexCells[i][j].setter(0);
			}}
		if(counter17%2==0){
			for(int i=0;i<l-1;i++){
				b1=arr7[i];
				b2=arr8[i];
				hexCells[b1-1][b2].setter(2);
			}
			arr7[l-1]=0;
			arr8[l-1]=0;
			l--;
			for(int i=0;i<f;i++){
				a1=arr5[i];
				a2=arr6[i];
				hexCells[a1-1][a2].setter(1);
			}}
		if(counter17%2==1){
			for(int i=0;i<f-1;i++){
				a1=arr5[i];
				a2=arr6[i];
				hexCells[a1-1][a2].setter(1);
			}
			arr5[f-1]=0;
			arr6[f-1]=0;
			f--;
			for(int i=0;i<l;i++){
				b1=arr7[i];
				b2=arr8[i];
				hexCells[b1-1][b2].setter(2);
			}}}
	if(ctr3==1){
		hexCells=new Cell*[number];
		for(int i=0;i<number;i++){
			hexCells[i]=new Cell[number];
		}
		for(int i=0;i<number;i++){
			for(int j=0;j<number;j++){
				hexCells[i][j].setter(0);
			}}
		a1=0,a2=0,b1=0,b2=0;
		for(int i=0;i<f-1;i++){
			a1=arr5[i];
			a2=arr6[i];
			hexCells[a1-1][a2].setter(1);
		}
		
		for(int i=0;i<l-1;i++){
			b1=arr7[i];
			b2=arr8[i];
			hexCells[b1-1][b2].setter(2);
		}	
		arr5[f-1]=0;
		arr6[f-1]=0;
		arr7[l-1]=0;
		arr8[l-1]=0;
		f--;
		l--;
	}}
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


/*Ifstream operator
I am  reading it in the file.
in the first line, I read who is on the turn.if there is one the turn is user1 or user,if there is two the turn is user2 
On the second line, I read the the board size.
In the third line, I read the number of moves of user1.
In the fourth line, I read the number of moves of user2.

thanks to the fifth line, I determine who the game is playing against.if there is three the game is user1VSuser2,
if there is four the game is userVScomputer.

On the sixth line, you are reading the coordinates of user1's moves.
On the seventh line, you read the coordinates of user2's moves.
Thanks to the other lines, I print the last state of the game board on the screen.*/
ifstream &operator >>(ifstream &input,const Hex &obj){
	int number=0,number2=0;
	char str;
	string str2,str3;
	int counter=0;

	if(obj.ctr5==0){
		getline(input,str2);
		getline(input,str2);
		getline(input,str2);
		getline(input,str2);
		getline(input,str2);
		getline(input,str2);
		getline(input,str2);
		
		
		
		while(getline(input,str2)){    //I press the game board in the file.
			cout<<str2<<endl;
		}
	}
	if(obj.ctr5==1){
		int num7=0;
		input>>str;
		obj.num=(int)str-48; //I determine who wins the game. If the number read is 1, then the turn is user1, if the number read is 2, then the turn is user2.
		input>>str;
		obj.num2=(int)str-48; //I'm reading the size of the game board.
		
		/*I adjusted my code according to the different situations of the game board.*/
		if(obj.num2==1){
			input>>str;
			num7=(int)str-48;
			if(num7==0){
				obj.num2=10;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==1){
				obj.num2=11;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==2){
				obj.num2=12;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==3){
				obj.num2=13;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==4){
				obj.num2=14;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==5){
				obj.num2=15;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==6){
				obj.num2=16;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==7){
				obj.num2=17;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==8){
				obj.num2=18;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==9){
				obj.num2=19;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}}
		if(obj.num2==2){	
			input>>str;
			num7=(int)str-48;
			if(num7==0 ){
				obj.num2=20;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==1){
				obj.num2=21;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==2){
				obj.num2=22;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==3){
				obj.num2=23;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==4){
				obj.num2=24;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==5){
				obj.num2=25;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==6){
				obj.num2=26;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==7){
				obj.num2=27;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==8){
				obj.num2=28;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}
			if(num7==9){
				obj.num2=29;
				input>>str;
				obj.f=(int)str-48;
				input>>str;
				obj.l=(int)str-48;
				input>>str;
				obj.who_vs_who=(int)str-48;
			}}	
		if(obj.num2<10){
			input>>str;
			obj.f=(int)str-48;
			input>>str;
			obj.l=(int)str-48;
			input>>str;
			obj.who_vs_who=(int)str-48;
		}
	}
	if(obj.ctr5==2){
		int num3=0,num4=0,num5=0,num6=0;
		getline(input,str3);
		getline(input,str3);
		getline(input,str3);
		getline(input,str3);
		getline(input,str3);
		getline(input,str3);

		/*I get the coordinates of the players from the file.*/
		if(obj.num2>=10){
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
					obj.arr5[number]=num3;
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
					obj.arr6[number2]=num5;
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
					obj.arr5[number]=num3;
					number++;
				}}
			num3=0,num4=0,num5=0,num6=0;
			number2=0;
			number=0;
			getline(input,str3);

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
					obj.arr7[number]=num3;
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
					obj.arr8[number2]=num5;
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
					obj.arr7[number]=num3;
					number++;
				}}}

		if(obj.num2<10){
			for(int i=0;i<100;i++){
				if(str3[i]==':'){
					break;
				}
				
				if(i%2==0){
					obj.arr5[number]=(int)str3[i]-48;
					number++;
					
				}
				if(i%2==1){
					obj.arr6[number2]=(int)str3[i]-48;
					number2++;
				}}
			number2=0;
			number=0;
			getline(input,str3);
			for(int i=0;i<100;i++){
				if(str3[i]==':'){
					break;
				}
				if(i%2==0){
					obj.arr7[number]=(int)str3[i]-48;
					number++;
					
				}
				if(i%2==1){
					obj.arr8[number2]=(int)str3[i]-48;
					number2++;
				}}}
	}
	return input;	
}

/*I am using ifstream operator  in load function*/
void Hex::load(const string &file_name)const{
	ifstream file,file2,file3;
	
	file.open(file_name);
	file2.open(file_name);
	file3.open(file_name);
	
	if(!file.is_open()){
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	file>>*this;
	file.close();
	ctr5=1;

	if(!file2.is_open()){
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	file2>>*this;
	file2.close();
	ctr5=2;
	
	if(!file3.is_open()){
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	file3>>*this;
	
	file3.close();
}
/*Ofstream operator
I got the file name
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
ofstream &operator <<(ofstream &output,const Hex &obj){
	int counter=0,counter2=0;
	int t=obj.number+1;
	
	output<<obj.wch_user<<endl;
	output<<obj.number<<endl;
	output<<obj.f<<endl;
	output<<obj.l<<endl;
	output<<obj.who_vs_who<<endl;
	
	if(obj.wch_user==1){
		if(obj.number>=10){
			for(int i=0;i<obj.f;i++){
				if(i==obj.f-1){
					output<<obj.arr5[i]<<","<<obj.arr6[i]<<":";
					break;
				}
				output<<obj.arr5[i]<<","<<obj.arr6[i]<<".";

			}
			output<<endl;
			for(int i=0;i<obj.l;i++){
				if(i==obj.l-1){
					output<<obj.arr7[i]<<","<<obj.arr8[i]<<":";
					break;
				}	
				output<<obj.arr7[i]<<","<<obj.arr8[i]<<".";
			}
			output<<endl;
		}
		else{
			for(int i=0;i<obj.f;i++){
				if(i==obj.f-1){
					output<<obj.arr5[i]<<obj.arr6[i]<<":";
					break;
				}
				output<<obj.arr5[i]<<obj.arr6[i];

			}
			output<<endl;
			for(int i=0;i<obj.l;i++){
				if(i==obj.l-1){
					output<<obj.arr7[i]<<obj.arr8[i]<<":";
					break;
				}	
				output<<obj.arr7[i]<<obj.arr8[i];
			}
			output<<endl;
		}}
	if(obj.wch_user==2){
		if(obj.number>=10){
			for(int i=0;i<obj.f;i++){
				if(i==obj.f-1){
					output<<obj.arr5[i]<<","<<obj.arr6[i]<<":";
					break;
				}
				output<<obj.arr5[i]<<","<<obj.arr6[i]<<".";

			}
			output<<endl;
			for(int i=0;i<obj.l;i++){
				if(i==obj.l-1){
					output<<obj.arr7[i]<<","<<obj.arr8[i]<<":";
					break;
				}	
				output<<obj.arr7[i]<<","<<obj.arr8[i]<<".";
			}
			output<<endl;
		}
		else{
			for(int i=0;i<obj.f;i++){
				if(i==obj.f-1){
					output<<obj.arr5[i]<<obj.arr6[i]<<":";
					break;
				}
				output<<obj.arr5[i]<<obj.arr6[i];
			}
			output<<endl;
			for(int i=0;i<obj.l;i++){
				if(i==obj.l-1){
					output<<obj.arr7[i]<<obj.arr8[i]<<":";
					break;
				}	
				output<<obj.arr7[i]<<obj.arr8[i];
			}
			output<<endl;
		}}
	CellState cell1=dot;
	CellState cell2=cross;
	CellState cell3=circle;

	for(int i=0;i<obj.number;i++){
		if(i==0){
			output<<"-----------X SIDE-----------"<<endl;
			output<<"     ";
												
			for(char i=65;i<65+obj.number;i++){
				output<<i<<"  ";
			}
			output<<endl;
		}
		if(i<6){
			output<<obj.arr[i]<<"  ";
			output<<i+1;
		}
		if(i>=6){
			output<<"   "<<i+1;
		}
		for(int k=0;k<i;k++){
			output<<"  ";
		}
		/*Thanks to the enum structure, I press the game board to the screen.*/
		for(int j=0;j<obj.number;j++){
			counter=0,counter2=0;

			if(obj.hexCells[i][j].getCell()==cell2 && obj.hexCells[i][j].getRow()==cell2){
				output<<" X ";
				counter++;
			}
							
			if(obj.hexCells[i][j].getCell()==cell3 && obj.hexCells[i][j].getRow()==cell3){
				output<<" O ";
				counter2++;
			}

			if(obj.hexCells[i][j].getCell()==cell1 && obj.hexCells[i][j].getRow()==cell1 && counter==0 && counter2==0){
				output<<" . ";
		}}
		for(int j=0;j<obj.number;j++){
			if(j==obj.number-1){
				for(;t>0;t--){
					output<<"  ";
				}
				if(i<6){
					output<<obj.arr[i];
				}
				t=obj.number-i;
			}}
			if(i==obj.number-1){
				output<<endl;
				output<<"-----------X SIDE-----------"<<endl;
			}
			output<<endl;
		}
	return output;	
}
/*I am using ofstream operator  in save function*/
void Hex::save(const string &file_name)const{
	ofstream file;
	string str;
	file.open(file_name);
	
	if(!file.is_open()){
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	
	file<<*this;

	file.close();
}		

//for Computer
/*The computer randomly puts its moves in 6 directions around the coordinates entered by the user. 
If the user puts X in a coordinate which has full 6 directions on the game board, 
then the computer puts another part of the board that is currently empty.
I used vector as an extra in this assignment.
And  it returns the Cell.
*/		
Hex::Cell Hex::play()const{
	int counter8=0;
	
	int z=0,k=0;
	char num2;
	int num3=0,flag4=1,m=0,flag2=1,flag=1,counter7=0,y=0,t=0,l=0;
	int arr3[100];
	char arr4[100];
	int number3=0,num4=0;
	char num1[15];
	Hex :: Cell cells3;
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
			cells3.setRow(num4);
			cells3.setCell(number3);
			flag4=0;
			cout<<num2<<num4<<endl;
		}
		b++;
	}
	return cells3;
}
/*the players who make the X and O moves in the game.
Score function adjusted according to how close they are to winning.
For example, on a 6x6 game board. 
If the player making X moves made 5 moves from top to bottom, the score is 5 for its
And if his score is 6, he already wins the game.
*/		
int *Hex::score()const{
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
//for User
/*the function I created for the moves made by the users.*/
void Hex::play(int &number2,int num3){
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
		hexCells=new Cell*[number];

		for(int i=0;i<number;i++){
			hexCells[i]=new Cell[number];
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
			int counter3=0,counter4=0,counter5=0,counter6=0,counter10=0,counter13=0,counter14=0,counter15=0,counter16=0;
			num9=0,num10=0,num11=-1;
			auto flag5=flag3;
//////////*I want the coordinates for X from the first user.*////////////	
			char file_name[20];
			
			while(flag5!=0){
				/*I write the user that she can use the SAVE and LOAD commands if they want.*/
				cout<<"//////////////////////////////////////////////////////////////////////////////////////"<<endl;
				cout<<endl<<"!!!Please write SAVE or LOAD for save or load the current game status!!!"<<endl;
				cout<<"!!!Please write UNDO for undo the last play!!!"<<endl;
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
				//I am using my UNDO operators in this.
				/*If there is no move to for the undo, a warning message is sent to the user.*/
				if(num1[0]=='U' && num1[1]=='N' && num1[2]=='D' && num1[3]=='O'){
					if(count18==0){
						cout<<"Please firstly make a move"<<endl;
					}			
					if(count18>0){	
						if(ctr3==0){
							--(*this);
							count18=count18-1;
							counter17++;
							Current_board();
						}
						if(ctr3==1){
							(*this)--;
							count18=count18-2;
							Current_board();
						}}
					counter15++;
					cntr1=1;
					counter13++;		
				}
				/*If the user has entered the SAVE command, 
				I am saving the last image of the game and the latest information of the game.*/
				if(num1[0]=='S' && num1[1]=='A' && num1[2]=='V' && num1[3]=='E'){
					cin>>file_name;	
					if(ctr3==0){
						if(counter17%2==0){
							wch_user=1;
							who_vs_who=3;
							save(file_name);
						}
						if(counter17%2==1){
							wch_user=2;
							who_vs_who=3;
							save(file_name);
						}
					}
					if(ctr3==1){
						wch_user=1;
						who_vs_who=4;
						save(file_name);
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
					
					load(file_name);
					ctr5=0;
					number=num2;
					
					e=number;
					int x1=Current_With(num2);
					int x2=Current_height(num2);
					cout<<endl<<"The current width:"<<x1<<endl;
					cout<<"The current height:"<<x2<<endl;
					
					count18=Hex::Marked(f,l);
					hold4=count18;
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
					hexCells=new Cell*[number];

					for(int i=0;i<number;i++){
						hexCells[i]=new Cell[number];
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
						if(num==1 ){
							cout<<"The turn was at User."<<endl;
						}
						
						ctr3=1;	

						nbr=num;
						nbr2=num2;
						
						flag5=0;
						counter13++;
						counter16++;
					}
					if(who_vs_who==3){
						if(num==1 ){
							counter17=0;
							cout<<"The turn was at User1."<<endl;
							counter13++;
							flag5=0;
							nbr=1;
						}
						if(num==2){
							counter17=1;
							cout<<"The turn was at User2."<<endl;
							flag3=0;
							flag5=0;
							counter13++;
							nbr=2;
						}
						
						ctr3=0;	

						nbr=num;
						nbr2=num2;
						f=f;
						l=l;
						counter13++;
						counter16++;
					}
					num5=0;
					if(num==1 && counter16==0){
						counter17=0;
						cout<<"The turn was at User1."<<endl;
						counter13++;
						flag5=0;
						nbr=1;
					}
					if(num==2 && counter16==0){
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
					num1[3]=0;
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
				if(nbr==0){
					if(ctr3==0){
						Hex :: Cell cells;
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
						count18=Hex::Marked(f,l);
						hold4=count18;
						
						cout<<endl;
						cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
						int *arr18=score();
						cout<<"The score of User1 : "<<arr18[0]<<endl;
						cout<<"The score of User2 : "<<arr18[1]<<endl;
					}
					if(ctr3==1){
						Hex :: Cell cells;
						cells.setRow(num3);
						cells.setCell(number2);
						Hex::c=num3;
						Hex::d=num1[0];
						
						arr5[f]=cells.getRow();
						arr6[f]=cells.getCell();
						f++;
						
						hexCells[num3-1][number2].setter(1);
						count18=Hex::Marked(f,f-1);
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
							Hex :: Cell cells;
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
							count18=Hex::Marked(f,l);
							hold4=count18;
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
							int *arr18=score();
							cout<<"The score of User1 : "<<arr18[0]<<endl;
							cout<<"The score of User2 : "<<arr18[1]<<endl;
						}	
						if(ctr3==1){
							Hex :: Cell cells;
							cells.setRow(num3);
							cells.setCell(number2);
							Hex::c=num3;
							Hex::d=num1[0];
							
							arr5[f]=cells.getRow();
							arr6[f]=cells.getCell();
							f++;
							hexCells[num3-1][number2].setter(1);
							count18=Hex::Marked(f,l);
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
							Hex :: Cell cells2;
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
							count18=Hex::Marked(f,l);
							hold4=count18;
							cout<<endl;
							cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
							int *arr18=score();
							cout<<"The score of User1 : "<<arr18[0]<<endl;
							cout<<"The score of User2 : "<<arr18[1]<<endl;
						}
						if(ctr3==1){
							Hex :: Cell cells;
							cells.setRow(num3);
							cells.setCell(number2);
							Hex::c=num3;
							Hex::d=num1[0];
							
							arr5[f]=cells.getRow();
							arr6[f]=cells.getCell();
							f++;
							hexCells[num3-1][number2].setter(1);
							
							count18=Hex::Marked(f,l);
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
				Current_board();
				int counter=0,counter2=0;
				int x3=Game_End(ctr3);
				
				if(x3==1){
					cout<<"User1 is won"<<endl;
					flag2=0;
					flag3=0;
					counter=1;
					f=0;
					l=0;
					counter17=0;
					if(hold3==1){
						Hex::hold2=Hex::hold4;
						if(hold1==hold2){
							number2=18;
						}
					}	
					if(hold3==0){
						hold1=Hex::hold4;
						hold4=0;
						hold3++;
					}
					hold5++;
				}
				if(x3==2){
					cout<<"User2 is won"<<endl;
					flag2=0;
					flag3=0;
					counter=1;
					f=0;
					l=0;
					counter17=0;
					if(hold3==1){
						Hex::hold2=Hex::hold4;
						if(hold1==hold2){
							number2=18;
						}
					}		
					if(hold3==0){
						hold1=Hex::hold4;
						hold4=0;
						hold3++;
					}
					hold5++;
				}
				if(x3==3){
					cout<<"User is won"<<endl;
					flag2=0;
					flag3=0;
					counter=1;
					f=0;
					l=0;
					counter17=0;
					if(hold3==1){
						Hex::hold2=Hex::hold4;
						if(hold1==hold2){
							number2=18;
						}
					}	
					if(hold3==0){
						hold1=Hex::hold4;
						hold4=0;
						hold3++;
					}
					hold5++;
				}
				flag3=0;
				t=number+1;
				if(ctr3==1 && counter==0){
					Hex::Cell cells4;
					cells4=play();
					
					arr7[l]=cells4.getRow();
					arr8[l]=cells4.getCell();
					l++;
					int n1=0,n2=0;
					n1=cells4.getRow();
					n2=cells4.getCell();
					hexCells[n1-1][n2].setter(2);
					
					Current_board();
					
					count18=Hex::Marked(f,l);
					hold4=count18;
					cout<<endl;
					cout<<"The number of marked(non-empty) cells in all the games:"<<count18<<endl;
					
					int *arr18=score();
					cout<<"The score of User : "<<arr18[0]<<endl;
					cout<<"The score of Computer : "<<arr18[1]<<endl;
					
					int x4=Game_End(ctr3);
					if(x4==4){
						cout<<endl<<"Computer is won"<<endl;
						flag2=0;
						flag3=0;
						f=0;
						l=0;
						counter17=0;
						if(hold3==1){
							Hex::hold2=Hex::hold4;
							if(hold1==hold2){
								number2=18;
							}
						}	
						if(hold3==0){
							hold1=Hex::hold4;
							hold4=0;
							hold3++;
						}
						
						hold5++;
					}
				}}
			g++;
		}}}
/*i am calling my member functin in this menu function 
it is take x2 variable for the indicate equal of the game.
*/		
void Hex::menu(int &x2){
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
			if(number2==18){
				x2=18;
			}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (User vs computer)					
		else if(option==2){
			cout<<endl;
				
			number2=1;
			play(number2,num3);
			if(number2==18){
				x2=18;
			}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////				
		else{
			cerr<<endl<<"invalid option."<<endl;
			cerr<<"Please select again."<<endl;
		}
}