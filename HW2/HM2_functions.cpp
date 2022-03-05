//YunusEmreGeyik-1801042635
#include "HM2.h"
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <cstdlib>
using namespace  std;

int fill_zero(int arr[12][12],int number){
	for(int i=0;i<number;i++){
		for(int j=0;j<number;j++){
			arr[i][j]=0;
		}
	}
	return arr[12][12];
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

void load(string file_name,int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &num,int &num2,int &f,int &l,int &who_vs_who){
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
						
					}}
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


void save(string file_name,int winning[12][12],int winning2[12][12],char arr[7],int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &number,int f,int l,int wch_user,int who_vs_who){
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

			if(winning[i][j]==cell2){
				file<<" X ";
				counter++;
			}
			if(winning2[i][j]==cell3){
				file<<" O ";
				counter2++;
			}
			if(winning[i][j]==cell1 && counter==0 && counter2==0){
				file<<" . ";
			}
		}
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
/*I take the size of the board from the user.
If he enters an invalid value, I want it again.*/
void take_board_size(int &number){
	int number4=0,flag3=1;
	int count=0;
	int arr2[7]={6,7,8,9,10,11,12};
	int k=6;
	
	int counter9=0;
	
	while(flag3!=0){
		counter9=0;
		cout<<"Plaese enter size of board(line X column)(6x6,7x7, 8x8, 9x9, 10x10, 11x11 or 12x12):"<<endl;
		
		cout<<"Line:";
		cin>>number;
				
		cout<<"Column:";
		cin>>number4;
			
		for(int i=0;i<7;i++){
			if(number==arr2[i] && number4==arr2[i]){
				flag3=0;
				count+=1;
			}}
		if(count!=0){
			break;
		}
		if(counter9==0){
			if (!(number) || !(number4)){
				cout <<endl<<"Please enter numbers only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
				counter9+=1;
			}}
		if(counter9==0){	
			for(int i=0;i<7;i++){
				if(number!=number4){
					cout<<"Please enter right board size(line and column)"<<endl<<endl;
					break;
				}
				else if(number!=arr2[i] || number4!=arr2[i]){
					cout<<"Please enter right board size(line and column)"<<endl<<endl;
					break;
				}}}}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////*I press the blank board to the screen.*//////////////////////////////////////////
//////////////*For the user entering X, the corners on the board are the upper and lower corners.*////////////////////
////////////*For the user who enters an O, the corners on the board are the left and right corners.*///////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////				
void first_board_view(const int number,int &t){
	char arr[7]="O SIDE";
	t=number+1;
	for(int i=0;i<number;i++){
		if(i==0){
			cout<<"--------------X SIDE--------------"<<endl;
			cout<<"     ";
				
			for(char i=65;i<65+number;i++){
				cout<<i<<"  ";
			}
			cout<<endl;}
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
	}}
/////////////*I ask the user how to play the game.(User vs. User) or (User vs. Computer)*//////////////////////
void who_vs_who(int &option){
	cout<<endl;
			
	cout<<"How do you want to play?"<<endl;
	cout<<"1.(User X User)"<<endl;
	cout<<"2.(User X Computer)"<<endl;
			
	cout<<"Please select an option:";
	cin>>option;
			
	if (!(option)){
		cout <<endl<<"Please enter numbers only."<<endl;
		cin.clear();
		cin.ignore(100,'\n');
	}}
///////////////////////*if the user selects (User vs. User) option */////////////////////////////
void User_vs_User(int arr5[100],int arr6[100],int arr7[100],int arr8[100],int winning[12][12],int winning2[12][12],int arr3[12],char arr4[12],int &flag,int number,int &nbr,int &nbr2,int &f,int &l,int &h){
	int counter10=0,counter11=0,counter12=0;
	char arr[7]="O SIDE";
	char num1[15],num2[15];
	
	int num3=0,num4=0,num5=0,num6=0,num9=0,num10=0,num11=0;
	int g=0,m=0;
	int x=0,d=0,z=0,k=0;
	int ctr1=0,ctr2=0;

	int number3=0,y=0,t=0;
	
	CellState cell1=dot;
	CellState cell2=cross;
	CellState cell3=circle;
		
	decltype(number3) number2;
	number2=0;
	
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
	}
	int who_vs_who=0;
	int flag2=1;
	
	g=f;
	m=l;
	while(flag2!=0){
		int flag3=1,flag4=1;
////////////////////////////////////////////(USER1)/////////////////////////////////////////////////////////////////  			
		while(flag3!=0 && ctr1==1){
			int counter3=0,counter4=0,counter5=0,counter6=0,counter10=0,counter13=0,counter14=0,counter15=0,counter16=0;
			num9=0,num10=0,num11=-1;
			auto flag5=flag3;
//////////*I want the coordinates for X from the first user.*////////////	
			char file_name[20];
			
			while(flag5!=0){

				/*I write the user that she can use the SAVE and LOAD commands if they want.*/

				cout<<endl<<"!!!Please write SAVE or LOAD for save or load  the current game status!!!"<<endl;
				cout<<"USER1(X)=";
				cin>>num1;
				int cntr1=0,cntr2=0;
				counter13=0;
				
				number2=(int)num1[0]-65;
				num3=(int)num1[1]-48;
				num9=(int)num1[2]-48;
				num11=(int)num1[3]-48;
				num11=-1;
				
				/*If the user has entered the SAVE command, 
				I am saving the last image of the game and the latest information of the game.*/

				if(num1[0]=='S' && num1[1]=='A' && num1[2]=='V' && num1[3]=='E'){
					
					cin>>file_name;	

					save(file_name,winning,winning2,arr,arr5,arr6,arr7,arr8,number,f,l,1,3);
					
					cntr1=1;
					counter15++;
				}

				/*If the user uses the LOAD command, the final state of the game in the entered file name is printed on the screen. 
				And  game is continued  with The that game.*/
				if(num1[0]=='L' && num1[1]=='O' && num1[2]=='A' && num1[3]=='D'){
					
					cin>>file_name;
								
					int num7=0,num8=0;
					
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
					
					load(file_name,arr5,arr6,arr7,arr8,num7,num8,f,l,who_vs_who);
					number=num8;
					winning[12][12]=fill_zero(winning,number);
					winning2[12][12]=fill_zero(winning2,number);
					

					/*If who_vs_who 4 is coming, the status of the players is changing.
						I switch to the User_vs_Computer function*/

					if(who_vs_who==4){
						if(num7==1){
							cout<<"The turn was at User."<<endl;
						}
						h=who_vs_who;
						nbr=num7;
						nbr2=num8;
						f=f;
						l=l;
						
						flag5=0;
						flag3=0;
						flag2=0;
						flag4=0;
						counter13++;
						counter16++;
					}
					num5=0;
					nbr=1;
					if(num7==1 && counter16==0){
						cout<<"The turn was at User1."<<endl;
						counter13++;
						flag5=0;
					}
					if(num7==2 && counter16==0){
						cout<<"The turn was at User2."<<endl;
						flag3=0;
						flag5=0;
						counter13++;
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
					cout<<num3<<endl;
					
					num10=num3*10;
					num3=num10+num9;
					
					cout<<num9<<endl;
					cout<<num3<<endl;
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
			for(int i=65;i<65+number;i++){
				if(num1[0]==arr4[y]){
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
					arr5[f]=num3;
					arr6[f]=number2;
					
					winning[num3-1][number2]=1;
				}
				if(nbr==1 || nbr==2){
					if(num5!=0){
						arr5[f]=num3;
						arr6[f]=number2;
						
						winning[num3-1][number2]=1;
					}}
				if(nbr==1 || nbr==2){
					if(num5==0){	
						for(int i=0;i<f;i++){
							x=arr5[i]-1;
							d=arr6[i];
							
							winning[x][d]=1;
						}
						for(int i=0;i<l;i++){
							z=arr7[i]-1;
							k=arr8[i];
							
							winning2[z][k]=2;
						}
						arr5[f]=num3;
						arr6[f]=number2;

						winning[num3-1][number2]=1;
						num6++;
					}}
				num5++;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*The end of game for user1 is determined as follows.
If the user puts at least one X on each line, 
he wins the game because he will connect the Upper and Lower X corners with the X coordinates he entered.   
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////								
				for(int i=0;i<number;i++){
					for(int j=0;j<number;j++){
						if(winning[i][j]==1){
							counter10++;
							break;
						}}}
				if(counter10==number){
						flag=0;
						flag2=0;
						flag3=0;
						counter11=1;
				}
				flag3=0;
				int counter=0,counter2=0;
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
					/*I press my game board to the screen with the enum structure*/
					for(int j=0;j<number;j++){
						counter=0,counter2=0;

						if(winning[i][j]==cell2){
							cout<<" X ";
							counter++;
						}
							
						if(winning2[i][j]==cell3){
							cout<<" O ";
							counter2++;
						}
						if(winning[i][j]==cell1 && counter==0 && counter2==0){
							cout<<" . ";
						}}
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
				}
				f++;
			}
			g++;
		}
		ctr2=1;
		if(counter11==1){
			cout<<"User1 is won"<<endl;
			break;
		}	
////////////////////////////////////////////(USER2)/////////////////////////////////////////////////////////////////  					
///////*User2 is not much different from user1. Only at the end of the game, ///////////////
///////if User2 enters at least one O in each column, he wins the game. ///////////////////////////
////////Thus, he will combine the O corners on the left and right with the O coordinates he entered.*///////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while(flag4!=0 && ctr2==1){
			int counter3=0,counter4=0,counter5=0,counter6=0,counter12=0,counter13=0,counter14=0,counter15=0,counter16=0;
			int flag5=1;
			num9=0,num10=0,num11=-1;
			char file_name[20];
			cout<<endl;
			
			while(flag5!=0){	
				cout<<endl<<"!!!Please write SAVE or LOAD for save or load the current game status!!!"<<endl;
				cout<<"USER2(O)=";
				cin>>num2;
				
				int cntr1=0,cntr2=0;
				counter13=0;
				
				number3=(int)num2[0]-65;
				num4=(int)num2[1]-48;
				num9=(int)num2[2]-48;
				num11=(int)num2[3]-48;
				num11=-1;
				
				if(num2[0]=='S' && num2[1]=='A' && num2[2]=='V' && num2[3]=='E'){
					cin>>file_name;	
					save(file_name,winning,winning2,arr,arr5,arr6,arr7,arr8,number,f,l,2,3);
					
					cntr1=1;
					counter15++;
				}
				if(num2[0]=='L' && num2[1]=='O' && num2[2]=='A' && num2[3]=='D'){
					
					cin>>file_name;
								
					int num7=0,num8=0;
					
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

					load(file_name,arr5,arr6,arr7,arr8,num7,num8,f,l,who_vs_who);
					number=num8;
					winning[12][12]=fill_zero(winning,number);
					winning2[12][12]=fill_zero(winning2,number);
					
					if(who_vs_who==4){
						if(num7==1){
							cout<<"The turn was at User."<<endl;
						}
						h=who_vs_who;
						nbr=num7;
						nbr2=num8;
						f=f;
						l=l;

						flag5=0;
						flag3=0;
						flag2=0;
						flag4=0;
						counter13++;
						counter16++;
					}
								
					num5=0;
					nbr=1;

					if(num7==1 && counter16==0){
						cout<<"The turn was at User1."<<endl;
						flag4=0;
						flag5=0;
						counter13++;
					}
					if(num7==2 && counter16==0){
						cout<<"The turn was at User2."<<endl;
						flag5=0;
						counter13++;
						
					}
					cntr2=1;
					counter15++;
				}
				if(num11>=0 && num11<10 && counter15==0){
					flag5=0;
					cout<<"Please,pay attention to the number you entered"<<endl;
					counter13++;
				}
				if(number>=10 && num9>=0 && counter14==0 && counter15==0){
					num10=num4*10;
					num4=num10+num9;

					if(num4>number){
						flag5=0;
						cout<<"Please,pay attention to the number you entered"<<endl;
						counter13++;
						counter14++;
					}}
				if(number<10 && num9>=0 && counter14==0 && counter15==0){
					num10=num4*10;
					num4=num10+num9;

					if(num4>number){
						flag5=0;
						cout<<"Please,pay attention to the number you entered"<<endl;
						counter13++;
					}}	
				if(cntr1==0 && cntr2==0 && counter13==0){
					flag5=0;
				}}
			if (!(num2) && counter13==0){
				cout <<endl<<"Please enter letters only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}
			if (!(num4) && counter13==0){
				cout <<endl<<"Please enter numbers only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}			
			for(int p=0;p<m+1;p++){
				if(num4==arr5[p] && number3==arr6[p] && counter13==0){
					cout<<"This location is occupied!!!"<<endl;
					counter5+=1;
				}}
			for(int p=0;p<m;p++){	
				if(num4==arr7[p] && number3==arr8[p] && counter13==0){
					cout<<"This location is occupied!!!"<<endl;
					counter6+=1;
				}}
			for(int i=0;i<number;i++){
				if(num4==arr3[i]){
					counter4+=1;
				}}
			if(counter4!=1 && counter13==0){
				cout<<"Please,pay attention to the number you entered"<<endl;
			}
			y=0;
			for(int i=65;i<65+number;i++){
				if(num2[0]==arr4[y]){
					counter3+=1;
				}
				y++;
			}
			if(counter3!=1 && counter13==0){
				cout<<"Please,pay attention to the letter you entered"<<endl;
			}	
			if(counter4==1 && counter3==1 && counter5+counter6==0 && counter13==0){
				if(nbr==0){
					arr7[l]=num4;
					arr8[l]=number3;
					
					winning2[num4-1][number3]=2;
				}
				if(nbr==1 || nbr==2){
					if(num5!=0){
						arr7[l]=num4;
						arr8[l]=number3;

						winning2[num4-1][number3]=2;
					}}
				if(nbr==1 || nbr==2){
					if(num5==0){	
						for(int i=0;i<f;i++){
							x=arr5[i]-1;
							d=arr6[i];
							
							winning[x][d]=1;
						}
						for(int i=0;i<l;i++){
							z=arr7[i]-1;
							k=arr8[i];
							
							winning2[z][k]=2;
						}
						arr7[l]=num4;
						arr8[l]=number3;
						
						winning2[num4-1][number3]=2;
						num6++;
					}	
				}
				num5++;
				
				for(int i=0;i<number;i++){
					for(int j=0;j<number;j++){
						if(winning2[j][i]==2){
							counter12++;
							break;
						}}}
				int counter=0,counter2=0;
				flag4=0;
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
						counter=0,counter2=0;

						if(winning[i][j]==cell2){
							cout<<" X ";
							counter++;
						}
							
						if(winning2[i][j]==cell3){
							cout<<" O ";
							counter2++;
						}
						if(winning[i][j]==cell1 && counter==0 && counter2==0){
							cout<<" . ";
						}
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
				}
				l++;
				if(counter12==number){
					flag=0;
					flag2=0;
					flag4=0;
					cout<<"User2 is won"<<endl;
					break;
				}}
			m++;
		}
	ctr1=1;
	}}
//////////////////////////*if the user selects (User vs. Computer) option*///////////////////////		
void User_vs_Computer(int arr5[100],int arr6[100],int arr7[100],int arr8[100],int winning[12][12],int winning2[12][12],int arr3[12],char arr4[12],int &flag,int number,int nbr,int nbr2,int f,int l){
	int counter10=0,counter11=0,counter12=0,counter13=0,counter14=0;
	int h=0;
	char arr[7]="O SIDE";
	
	char num1[15];
	char num2;
	int num3=0,num4=0,num5=0,num9=0,num10=0,num11=-1;
	int x=0,d=0,z=0,k=0;

	int g=0,m=0;
	int flag2=1;
	int number2=0,number3=0,y=0,t=0;
	int counter8=0,counter7=0,counter17=0;
	int who_vs_who=0;
	CellState cell1=dot;
	CellState cell2=cross;
	CellState cell3=circle;

	if(nbr==1){
		number=nbr2;
		g=number;
	}
	while(flag2!=0){
		cout<<endl;
		int flag3=1,flag4=1;
		
		counter7=0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*User moves X in this part. There is no difference from User1 who enters the X coordinates in (User 1 vs User2).*///////////		
/////////////////////////////////////////(USER)////////////////////////////////////////////////////////////////////  					
		while(flag3!=0){
			int counter3=0,counter4=0,counter5=0,counter6=0,counter10=0,counter13=0,counter14=0,counter15=0,counter16=0;
			int flag5=1;			
			char file_name[20];
		
			while(flag5!=0){	
				cout<<endl<<"!!!Please write SAVE or LOAD for save or load  the current game status!!!"<<endl;
				cout<<"USER(X)=";
				cin>>num1;
				
				int cntr1=0,cntr2=0;
				counter13=0;
				
				number2=(int)num1[0]-65;
				num3=(int)num1[1]-48;
				num9=(int)num1[2]-48;
				num11=(int)num1[3]-48;
				num11=-1;
				
				if(num1[0]=='S' && num1[1]=='A' && num1[2]=='V' && num1[3]=='E'){
					cin>>file_name;	
					save(file_name,winning,winning2,arr,arr5,arr6,arr7,arr8,number,f,l,1,4);
					cntr1=1;
					counter15++;
				}
				if(num1[0]=='L' && num1[1]=='O' && num1[2]=='A' && num1[3]=='D'){
					cin>>file_name;
					int num7=0,num8=0;
					
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

					load(file_name,arr5,arr6,arr7,arr8,num7,num8,f,l,who_vs_who);
					number=num8;
					
					winning[12][12]=fill_zero(winning,number);
					winning2[12][12]=fill_zero(winning2,number);
					
					/*If who_vs_who 3 is coming, the status of the players is changing.
						I switch to the User_vs_User function*/

					if(who_vs_who==3){
						if(num7==1){
							cout<<"The turn was at User1."<<endl;
						}
						if(num7==2){
							cout<<"The turn was at User2."<<endl;
						}
						int arr9[12];
						char arr10[12];
						y=0;
						for(int i=0;i<number;i++){
							arr9[i]=i+1;
						}
						for(int i=65;i<65+number;i++){
							arr10[y]=i;
							y++;
						}
						flag2=0;
						flag5=0;
						flag3=0;
						flag4=0;
						counter13++;
						User_vs_User(arr5,arr6,arr7,arr8,winning,winning2,arr9,arr10,flag,number,num7,num8,f,l,h);
					}	
								
					num5=0;
					nbr=1;

					if(num7==1){
						cout<<"The turn was at User."<<endl;
						counter16++;
						flag5=0;
						nbr=1;
						num5=0;
					}
					cntr2=1;
					counter15++;
				}
				if(num11>=0 && num11<10 && counter15==0){
					flag5=0;
					cout<<"deneme3"<<endl;
					cout<<"Please,pay attention to the number you entered"<<endl;
					counter13++;
					counter14++;
				}
				if(number>=10 && num9>=0 && counter14==0 && counter15==0){
					num10=num3*10;
					num3=num10+num9;
					cout<<"deneme2"<<endl;
					if(num3>number){
						flag5=0;
						cout<<"Please,pay attention to the number you entered"<<endl;
						counter13++;
					}}
				if(number<10 && num9>=0 && counter14==0 && counter15==0){
					num10=num3*10;
					num3=num10+num9;
					cout<<"deneme1"<<endl;
					if(num3>number){
						flag5=0;
						cout<<"Please,pay attention to the number you entered"<<endl;
						counter13++;
					}}
				if(cntr1==0 && cntr2==0 && counter13==0){
					flag5=0;
				}}
			
			if (!(num1) && counter13==0 && counter16==0){
				cout <<endl<<"Please enter letters only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}
			if (!(num3) && counter13==0 && counter16==0){
				cout <<endl<<"Please enter numbers only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}

			for(int p=0;p<g;p++){
				if(num3==arr5[p] && number2==arr6[p] && counter13==0 && counter16==0){
					cout<<"deneme1"<<endl;
					cout<<"This location is occupied!!!"<<endl;
					counter5+=1;
				}}
			for(int p=0;p<g;p++){	
				if(num3==arr7[p] && number2==arr8[p] && counter13==0 && counter16==0){
					cout<<"deneme2"<<endl;
					cout<<"This location is occupied!!!"<<endl;
					counter6+=1;
				}}
			for(int i=0;i<number;i++){
				if(num3==arr3[i]){
					counter4+=1;
				}}
			if(counter4!=1 && counter13==0 && counter16==0){
				cout<<"Please,pay attention to the number you entered"<<endl;
			}
			y=0;
			
			for(int i=65;i<65+number;i++){
				if(num1[0]==arr4[y]){
					counter3+=1;
				}
				y++;
			}
			if(counter3!=1 && counter13==0 && counter16==0){
				cout<<"Please,pay attention to the letter you entered"<<endl;
			}
			if(counter4==1 && counter3==1 && counter5+counter6==0 && counter13==0){
				if(nbr==0){
					arr5[f]=num3;
					arr6[f]=number2;
					
					winning[num3-1][number2]=1;
				}
				if(nbr==1 || nbr==2){
					if(num5!=0){
						arr5[f]=num3;
						arr6[f]=number2;
						
						winning[num3-1][number2]=1;
					}	
				}
				if(nbr==1 || nbr==2){
					if(num5==0){	
						for(int i=0;i<f;i++){
							x=arr5[i]-1;
							d=arr6[i];
							
							winning[x][d]=1;
						}
						for(int i=0;i<l;i++){
							z=arr7[i]-1;
							k=arr8[i];
							
							winning2[z][k]=2;
						}
						arr5[f]=num3;
						arr6[f]=number2;

						winning[num3-1][number2]=1;
					}	
				}
				num5++;
				
				for(int i=0;i<number;i++){
					for(int j=0;j<number;j++){
						if(winning[i][j]==1){
							counter10++;
							break;
						}}}
				if(counter10==number){
					flag=0;
					flag2=0;
					flag3=0;
					counter11=1;
				}
				flag3=0;
				int counter=0,counter2=0;
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
						counter=0,counter2=0;

						if(winning[i][j]==cell2){
							cout<<" X ";
							counter++;
						}
							
						if(winning2[i][j]==cell3){
							cout<<" O ";
							counter2++;
						}
						if(winning[i][j]==cell1 && counter==0 && counter2==0){
							cout<<" . ";
						}
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
				}
				f++;
			}
			g++;
		}
		if(counter11==1){
			cout<<"User is won"<<endl;
			break;
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*The computer randomly puts its moves in 6 directions around the coordinates entered by the user. 
If the user puts X in a coordinate which has full 6 directions on the game board, 
then the computer puts another part of the board that is currently empty.*/			

/////////////////////////////////////////(COMPUTER)////////////////////////////////////////////////////////////////////  
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
			for(int p=0;p<m+1;p++){
				if(num4==arr5[p] && number3==arr6[p]){
					counter5+=1;
					counter7+=1;
				}}
			for(int p=0;p<m;p++){	
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
				arr7[l]=num4;
				arr8[l]=number3;
				
				cout<<num2<<num4<<endl;


				winning2[num4-1][number3]=2;
							
				for(int i=0;i<number;i++){
					for(int j=0;j<number;j++){
						if(winning2[j][i]==2){
							counter12++;
							break;
						}}}
				int counter=0,counter2=0;
				flag4=0;
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
						counter=0,counter2=0;

						if(winning[i][j]==cell2){
							cout<<" X ";
							counter++;
						}
						if(winning2[i][j]==cell3){
							cout<<" O ";
							counter2++;
						}
						if(winning[i][j]==cell1 && counter==0 && counter2==0){
							cout<<" . ";
						}
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
				}
				l++;

				if(counter12==number){
					flag=0;
					flag2=0;
					flag4=0;
					cout<<"Computer is won"<<endl;
					break;
				}
			}
			m++;
		}}}
void make_board(){
	int number=0;
	int num7=0,num8=0,f=0,l=0;
	int flag=1;
	int y=0,h=0;
	
	int arr5[100];
	int arr6[100];
	int arr7[100];
	int arr8[100];

	int arr3[12];
	char arr4[12];
	int winning[12][12];
	int winning2[12][12];
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	(Accurate board size control)	
	int t=0;
	take_board_size(number);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////   (First view of the board)		
	first_board_view(number,t);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (How the user will play)		
	int option=0;
	who_vs_who(option);
		
	while(flag!=0){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (User1(X) vs. User2(O))			
		for(int i=0;i<number;i++){
			arr3[i]=i+1;
		}
		for(int i=65;i<65+number;i++){
			arr4[y]=i;
			y++;
		}
		if(option==1){
			cout<<endl;
			winning[12][12]=fill_zero(winning,number);
			winning2[12][12]=fill_zero(winning2,number);
					
			User_vs_User(arr5,arr6,arr7,arr8,winning,winning2,arr3,arr4,flag,number,num7,num8,f,l,h);
					
			if(h==4){
				option=2;
				number=num8;
			}}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (User vs computer)					
			else if(option==2){
				

				cout<<endl;
				int arr9[12];
				char arr10[12];
				y=0;
				for(int i=0;i<number;i++){
					arr9[i]=i+1;
				}
				for(int i=65;i<65+number;i++){
					arr10[y]=i;
					y++;
				}
				winning[12][12]=fill_zero(winning,number);
				winning2[12][12]=fill_zero(winning2,number);
				User_vs_Computer(arr5,arr6,arr7,arr8,winning,winning2,arr9,arr10,flag,number,num7,num8,f,l);
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////				
			else{
				cerr<<endl<<"invalid option."<<endl;
				cerr<<"Please select again."<<endl;
			}}
	return;
}

