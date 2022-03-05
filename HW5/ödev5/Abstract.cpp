#include "Abstract.h"
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <deque>

using namespace  std;

namespace Abstract_Class{
	/*This function checks whether the game loaded from the file is corrupt.*/
	//I did a check based on the number of X's and Os in the file.
	bool isValid(const AbstractHex *AbstractPtr){
		ifstream file;
		file.open(AbstractPtr->getFile_Name());
		if(!file.is_open()){
			cout<<"The file hasn't opened."<<endl;
			exit(0);
		}
		char *APtr=AbstractPtr->getPtr();

		int counter=0,counter2=0;
		for(int i=0;i<100;i++){
			if(APtr[i]=='X'){
				counter++;
			}
			if(APtr[i]=='O'){
				counter2++;
			}
		}
		if(counter-2!=AbstractPtr->geth3() && counter2!=AbstractPtr->geth4()){
			return false;
		}
		return true;
	}

	//My static variables
	char *AbstractHex::arr=nullptr;
	int AbstractHex::b=0;
	int AbstractHex::c=0;
	int AbstractHex::d=0;
	int AbstractHex::f=0;
	int AbstractHex::l=0;
	int AbstractHex::e=0;
	int AbstractHex::ctr3=0;
	int AbstractHex::ctr4=0;
	int AbstractHex::ctr5=0;
	int AbstractHex::counter17=0;
	int AbstractHex::hold1=0;
	int AbstractHex::hold2=0;
	int AbstractHex::hold3=0;
	int AbstractHex::hold4=0;
	int AbstractHex::wch_user=0;
	int AbstractHex::who_vs_who=0;
	int AbstractHex::num=0;
	int AbstractHex::num2=0;
	int AbstractHex::count18=0;
	int AbstractHex::h1=0;
	int AbstractHex::h2=0;
	int AbstractHex::h3=0;
	int AbstractHex::h4=0;
	
	/*A constructor of the AbstractHex class*/
	AbstractHex::AbstractHex(const int &x1,const int &x2):number(x1),hold5(x1),number_marked(x1),size(x2){
		arr5=new int[size];   					//array sizes are determined according to size
		arr6=new int[size];						//Arrays where I keep coordinates
		arr7=new int[size];
		arr8=new int[size];
		APtr=new char[size];
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
	
	AbstractHex::AbstractHex(const AbstractHex &object){   //Copy Constructor
		this->number=object.number;
		this->number_marked=object.number_marked;
		this->hold5=object.hold5;
		this->size=object.size;
		
		arr5=new int[this->size+1];
		arr6=new int[this->size+1];
		arr7=new int[this->size+1];
		arr8=new int[this->size+1];
		APtr=new char[this->size+1];
		arr=new char[7];

		arr5=object.arr5;
		arr6=object.arr6;
		arr7=object.arr7;
		arr8=object.arr8;
		APtr=object.APtr;
		arr=object.arr;
	}
	//Copy Assignment Operator
	AbstractHex& AbstractHex::operator=(const AbstractHex &object){
		if(this == &object){
			return *this;
		}
		else{
			delete []arr5;
			delete []arr6;
			delete []arr7;
			delete []arr8;
			delete []arr;
			delete []APtr;

			this->number=object.number;
			this->number_marked=object.number_marked;
			this->hold5=object.hold5;
			this->size=object.size;
			
			arr5=new int[this->size+1];
			arr6=new int[this->size+1];
			arr7=new int[this->size+1];
			arr8=new int[this->size+1];
			APtr=new char[this->size+1];
			arr=new char[7];

			arr5=object.arr5;
			arr6=object.arr6;
			arr7=object.arr7;
			arr8=object.arr8;
			APtr=object.APtr;
			arr=object.arr;

			return *this;
		}	
	}
	AbstractHex::~AbstractHex(){   //Destructor for the AbstractHex class
		if(hold5!=0){
			if(ctr4==0){
				delete []arr5;
				delete []arr6;
				delete []arr7;
				delete []arr8;
				delete []arr;
				delete []APtr;
				ctr4++;
			}}}
	/*i am calling my member functin in this menu function 
		it is take x2 variable for the indicate equal of the game.
	*/			
	void AbstractHex::menu(int &x2){
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
			}}
	///////////////////////////////////////////////////////////////////////////////////////////////////////	
	/*The function where I take the size of the game board from the user, 
		press the first version of the board on the screen and ask the user how they want to play the game.*/
	void AbstractHex::playGame(int &option){
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
	int AbstractHex::geth3 () const{    //Returns for the hold last coordinate's row.
		return this->h3;
	}
	int AbstractHex::geth4 () const{     //Set for the hold last coordinate's cell.
		return this->h4;
	}
	string AbstractHex::getFile_Name () const{       //Returns for the name of file.
		return this->file_name;
	}
	void AbstractHex::setFile_Name(const string &file_name){         //Set for the name of file.
		this->file_name=file_name;
	}
	/*gets a number from the user for the size of board*/
	void AbstractHex::setNumber(const int &number){
		this->number=number;
	}
	//returns the size of boar
	int AbstractHex::getNumber () const{
		return this->number;
	}
	/*gets a number from the user for the size of hold5 variable
		i am using this variable for the compere processes*/
	int AbstractHex::getHold5 () const{
		return this->hold5;
	}
	/*gets a number from the user for the size of array*/
	void AbstractHex::setHold5(const int &hold5){
		this->hold5=hold5;
	}
	/*returns the size of array*/
	int AbstractHex::getSize () const{
		return this->size;
	}
	/*gets a number from the user for the size of array*/
	void AbstractHex::setsize(const int &size){
		this->size=size;
	}
	/*gets a number from the user for the number_of_marked*/
	void AbstractHex::setNumber_Marked(const int &number_marked){
		this->number_marked=number_marked;
	}
	/*returns the number_of_marked*/
	int AbstractHex::getNumber_Marked () const{
		return this->number_marked;
	}
	/*static function that returns the number of cells that are marked*/
	int AbstractHex::numberofMoves(const int &f,const int &l){
		int count=f+l;
		return count;
	}
	/*function that returns the current width of the game board.*/
	int AbstractHex::Current_With(const int &x)const{
		return x;
	}
	/*function that returns the current height of the game board.*/
	int AbstractHex::Current_height(const int &y)const{
		return y;
	}
	/*Thanks to this function, I assign values to the coordinates of our Vector,1D Array and Template Variables which is cell type.*/
	/*I assigned 1 to places with X, 2 to places with 0, and 0 to places with dots.*/
	void AbstractHex::Cell::setter(const int &x){
		this->row=x;
		this->cell=x;
	}
	/*returns the letter in the column*/
	int AbstractHex::Cell::getCell()const{
		return this->cell;
	}
	/*returning the number on the line*/
	int AbstractHex::Cell::getRow()const{
		return this->row;
	}
	/*gets the letter in the column from the user*/
	void AbstractHex::Cell::setCell(const int &cell){
		this->cell=cell;
	}
	/*getting the number in the line from the user*/
	void AbstractHex::Cell::setRow(const int &row){
		this->row=row;
	}
	//function that returns the pointer holding the X and Os in the file.
	char* AbstractHex::getPtr()const{
		return this->APtr;
	}
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
	void AbstractHex::readFromFile(int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &num,int &num2,int &f,int &l,int &who_vs_who){
		ifstream file,file2,file3,file4;
		int number=0,number2=0;
		char str,str4;
		string str2,str3;
		int counter=0;
		
		file.open(file_name);
		file2.open(file_name);
		file3.open(file_name);
		file4.open(file_name);
		
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
		if(!file4.is_open()){
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
		
		
		int index=0;
		while(file4>>str4){
			if(str4=='X'){
				APtr[index]='X';
				index++;
			}
			if(str4=='O'){
				APtr[index]='O';
				index++;
			}
				
		}
		int num3=0,num4=0,num5=0,num6=0,num7=0;
		
		file2>>str;
		num=(int)str-48; //I determine who wins the game. If the number read is 1, then the turn is user1, if the number read is 2, then the turn is user2.
		file2>>str;
		num2=(int)str-48; //I'm reading the size of the game board.
		
		/*I adjusted my code according to the different situations of the game board.*/
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
				h3=f;
				h4=l;
			}
			if(num7==1){
				num2=11;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==2){
				num2=12;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==3){
				num2=13;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==4){
				num2=14;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==5){
				num2=15;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==6){
				num2=16;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==7){
				num2=17;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==8){
				num2=18;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==9){
				num2=19;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
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
				h3=f;
				h4=l;
			}
			if(num7==1){
				num2=21;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==2){
				num2=22;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==3){
				num2=23;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==4){
				num2=24;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==5){
				num2=25;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==6){
				num2=26;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==7){
				num2=27;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==8){
				num2=28;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}
			if(num7==9){
				num2=29;
				file2>>str;
				f=(int)str-48;
				file2>>str;
				l=(int)str-48;
				file2>>str;
				who_vs_who=(int)str-48;
				h3=f;
				h4=l;
			}}	
		if(num2<10){
			file2>>str;
			f=(int)str-48;
			file2>>str;
			l=(int)str-48;
			file2>>str;
			who_vs_who=(int)str-48;
			h3=f;
			h4=l;
		}
		
		getline(file3,str3);
		getline(file3,str3);
		getline(file3,str3);
		getline(file3,str3);
		getline(file3,str3);
		getline(file3,str3);

		/*I get the coordinates of the players from the file.*/
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
	/*The operator that compares the game of the first opened object with the game of the second opened object.
		for the their Game Boards are equal or no equal.Returns true if the games have a same Game Board.*/
	bool AbstractHex::operator==(const AbstractHex &object)const{
		if(number!=object.number){
			return false;
		}
		int counter=0;
		
		for(int i=0;i<100;i++){
			counter=0;
			for(int j=0;j<100;j++){
				if(arr5[i]==object.arr5[j] ){
					counter++;
				}
				if(j==99 && counter==0){
					return false;
				}
			}
		}
		for(int i=0;i<100;i++){
			counter=0;
			for(int j=0;j<100;j++){
				if(arr6[i]==object.arr6[j]){
					counter++;
				}
				if(j==99 && counter==0){
					return false;
				}
			}
		}
		for(int i=0;i<100;i++){
			counter=0;
			for(int j=0;j<100;j++){
				if(arr7[i]==object.arr7[j]){
					counter++;
				}
				if(j==99 && counter==0){
					return false;
				}
			}
		}
		for(int i=0;i<100;i++){
			counter=0;
			for(int j=0;j<100;j++){
				if(arr8[i]==object.arr8[j]){
					counter++;
				}
				if(j==99 && counter==0){
					return false;
				}
			}
		}
		return true;
	}

}