//YunusEmreGeyik-1801042635
#include "HM1.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace  std;


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
			}
		}
		if(count!=0){
			break;
		}
		if(counter9==0){
			if (!(number) || !(number4)){
				cout <<endl<<"Please enter numbers only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
				counter9+=1;
			}
		}
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
void first_board_view(int number,int &t){
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

void User_vs_User(int winning[12][12],int winning2[12][12],int arr3[12],char arr4[12],int &flag,int number){
		int counter10=0,counter11=0,counter12=0,counter13=0,counter14=0;
		char arr[7]="O SIDE";
		char num1,num2;
		int num3=0,num4=0;
		int f=0,l=0,g=0,m=0;
					
		int number2=0,number3=0,y=0,t=0;
		int flag2=1;
		int arr5[100];
		int arr6[100];
		int arr7[100];
		int arr8[100];
					
	while(flag2!=0){
		int flag3=1,flag4=1;
////////////////////////////////////////////(USER1)/////////////////////////////////////////////////////////////////  			
		while(flag3!=0){
			int counter3=0,counter4=0,counter5=0,counter6=0,counter10=0;

//////////*I want the coordinates for X from the first user.*////////////	

			cout<<"USER1(X)=";
			cin>>num1;
			cin>>num3;
			number2=(int)num1-65;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  the process that I do to prevent the user from entering numbers instead of letters 
or letters instead of numbers when entering the coordinates*/				
/////////////////////////////////////////////////////////////////////////////////////////////////////////////			
			if (!(num1)){
				cout <<endl<<"Please enter letters only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}
			if (!(num3)){
				cout <<endl<<"Please enter numbers only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}
/////////////*The operation I do to prevent the user from entering a coordinate in a previously entered coordinate.*//////		
			for(int p=0;p<g;p++){
				if(num3==arr5[p] && number2==arr6[p]){
					cout<<"This location is occupied!!!"<<endl;
					counter5+=1;
					}}
			for(int p=0;p<g;p++){	
				if(num3==arr7[p] && number2==arr8[p]){
					cout<<"This location is occupied!!!"<<endl;
					counter6+=1;
				}}
///////////*the action I take to prevent the user from going beyond the dimensions of the board.*/////////			

			for(int i=0;i<number;i++){
				if(num3==arr3[i]){
					counter4+=1;
				}}
			if(counter4!=1){
				cout<<"Please,pay attention to the number you entered"<<endl;
			}
			y=0;
			for(int i=65;i<65+number;i++){
				if(num1==arr4[y]){
					counter3+=1;
				}
				y++;
			}
			if(counter3!=1){
				cout<<"Please,pay attention to the letter you entered"<<endl;
			}
///////////////*If the user has entered a valid coordinate it goes into this if.*////////////////			
			if(counter4==1 && counter3==1 && counter5+counter6==0){
				arr5[f]=num3;
				arr6[f]=number2;
				winning[num3-1][number2]=1;
								
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
					for(int j=0;j<number;j++){
						counter=0,counter2=0;
										
						for(int p=0;p<f+1;p++){
							if(i+1==arr5[p] && j==arr6[p]){
								cout<<" X ";
								counter+=1;
							}}
						for(int n=0;n<l;n++){
							if(i+1==arr7[n] && j==arr8[n]){
								cout<<" O ";
								counter2+=1;
							}}
										
						if(counter==0 && counter2==0){
							cout<<" . ";
						}
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
			cout<<"User1 is won"<<endl;
			break;
		}	
////////////////////////////////////////////(USER2)/////////////////////////////////////////////////////////////////  					
///////*User2 is not much different from user1. Only at the end of the game, ///////////////
///////if User2 enters at least one O in each column, he wins the game. ///////////////////////////
////////Thus, he will combine the O corners on the left and right with the O coordinates he entered.*///////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while(flag4!=0){
			int counter3=0,counter4=0,counter5=0,counter6=0,counter12=0;
			
			cout<<endl;
			cout<<"USER2(O)=";
			cin>>num2;
			cin>>num4;
			int number3=(int)num2-65;
			
			if (!(num2)){
				cout <<endl<<"Please enter letters only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}
			if (!(num4)){
				cout <<endl<<"Please enter numbers only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}			
							
			for(int p=0;p<m+1;p++){
				if(num4==arr5[p] && number3==arr6[p]){
					cout<<"This location is occupied!!!"<<endl;
					counter5+=1;
				}}
			for(int p=0;p<m;p++){	
				if(num4==arr7[p] && number3==arr8[p]){
					cout<<"This location is occupied!!!"<<endl;
					counter6+=1;
				}}
			for(int i=0;i<number;i++){
				if(num4==arr3[i]){
					counter4+=1;
				}}
			if(counter4!=1){
				cout<<"Please,pay attention to the number you entered"<<endl;
			}
			y=0;
			for(int i=65;i<65+number;i++){
				if(num2==arr4[y]){
					counter3+=1;
				}
				y++;
			}
			if(counter3!=1){
				cout<<"Please,pay attention to the letter you entered"<<endl;
			}	
			if(counter4==1 && counter3==1 && counter5+counter6==0){
				arr7[l]=num4;
				arr8[l]=number3;
								
				winning2[num4-1][number3]=1;
								
				for(int i=0;i<number;i++){
					for(int j=0;j<number;j++){
						if(winning2[j][i]==1){
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
						counter=0;
						counter2=0;
										
						for(int p=0;p<f+1;p++){
							if(i+1==arr5[p] && j==arr6[p]){
								cout<<" X ";
								counter+=1;
							}}
											
						for(int n=0;n<l+1;n++){
							if(i+1==arr7[n] && j==arr8[n]){
								cout<<" O ";
								counter2+=1;
							}}
											
						if(counter==0 && counter2==0){
							cout<<" . ";
						}
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
		}}}

//////////////////////////*if the user selects (User vs. Computer) option*///////////////////////		

void User_vs_Computer(int winning[12][12],int winning2[12][12],int arr3[12],char arr4[12],int &flag,int number){
	
	int counter10=0,counter11=0,counter12=0,counter13=0,counter14=0;
	
	char arr[7]="O SIDE";
	
	char num1,num2;
	int num3=0,num4=0;
	
	int f=0,l=0,g=0,m=0;
	int flag2=1;
	int number2=0,number3=0,y=0,t=0;
	int counter8=0,counter7=0;
	int arr5[100];
	int arr6[100];
	int arr7[100];
	int arr8[100];

	while(flag2!=0){
		cout<<endl;
		int flag3=1,flag4=1;
		
		counter7=0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*User moves X in this part. There is no difference from User1 who enters the X coordinates in (User 1 vs User2).*///////////		

/////////////////////////////////////////(USER)////////////////////////////////////////////////////////////////////  					
		while(flag3!=0){
			int counter3=0,counter4=0,counter5=0,counter6=0,counter10=0;
						
			cout<<"USER(X)=";
			cin>>num1;
			cin>>num3;
			number2=(int)num1-65;
			
			if (!(num1)){
				cout <<endl<<"Please enter letters only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}
			if (!(num3)){
				cout <<endl<<"Please enter numbers only."<<endl;
				cin.clear();
				cin.ignore(100,'\n');
			}


			for(int p=0;p<g;p++){
				if(num3==arr5[p] && number2==arr6[p]){
					cout<<"This location is occupied!!!"<<endl;
					counter5+=1;
				}}
			for(int p=0;p<g;p++){	
				if(num3==arr7[p] && number2==arr8[p]){
					cout<<"This location is occupied!!!"<<endl;
					counter6+=1;
				}}
			for(int i=0;i<number;i++){
				if(num3==arr3[i]){
					counter4+=1;
				}}
			if(counter4!=1){
				cout<<"Please,pay attention to the number you entered"<<endl;
			}
			y=0;
			for(int i=65;i<65+number;i++){
				if(num1==arr4[y]){
					counter3+=1;
				}
				y++;
			}
			if(counter3!=1){
				cout<<"Please,pay attention to the letter you entered"<<endl;
			}
			if(counter4==1 && counter3==1 && counter5+counter6==0){
				arr5[f]=num3;
				arr6[f]=number2;
							
				winning[num3-1][number2]=1;
							
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
									
						for(int p=0;p<f+1;p++){
							if(i+1==arr5[p] && j==arr6[p]){
								cout<<" X ";
								counter+=1;
							}}
						for(int n=0;n<l;n++){
							if(i+1==arr7[n] && j==arr8[n]){
								cout<<" O ";
								counter2+=1;
							}}
						if(counter==0 && counter2==0){
							cout<<" . ";
						}
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
				num2=num1+1;
				number3=(int)num2-65;
			}
			//sol
			if(counter8==1){
				num4=num3;
				num2=num1-1;
				number3=(int)num2-65;
			}
			//sol-üst
			if(counter8==2){
				num4=num3-1;
				num2=num1;
				number3=(int)num2-65;
			}
			//sağ-üst
			if(counter8==3){	
				num4=num3-1;
				num2=num1+1;
				number3=(int)num2-65;
			}
			//sol-alt çapraz
			if(counter8==4){	
				num4=num3+1;
				num2=num1-1;
				number3=(int)num2-65;
			}
			//sağ-alt çapraz
			if(counter8==5){	
				num4=num3+1;
				num2=num1;
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


				winning2[num4-1][number3]=1;
							
				for(int i=0;i<number;i++){
					for(int j=0;j<number;j++){
						if(winning2[j][i]==1){
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
						counter=0;
						counter2=0;
									
						for(int p=0;p<f;p++){
							if(i+1==arr5[p] && j==arr6[p]){
								cout<<" X ";
								counter+=1;
							}}
						for(int n=0;n<l+1;n++){
							if(i+1==arr7[n] && j==arr8[n]){
								cout<<" O ";
								counter2+=1;
							}}
										
						if(counter==0 && counter2==0){
							cout<<" . ";
						}
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

int fill_zero(int arr[12][12],int number){
	for(int i=0;i<number;i++){
		for(int j=0;j<number;j++){
			arr[i][j]=0;
		}
	}
	return arr[12][12];
}

void make_board(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	(Accurate board size control)	
	int number=0,t=0;
	take_board_size(number);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////   (First view of the board)		
	char arr[7]="O SIDE";
	first_board_view(number,t);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (How the user will play)		
		int flag=1,flag2=1;
		int y=0;
		
		int arr3[12];
		char arr4[12];
		
		for(int i=0;i<number;i++){
			arr3[i]=i+1;
		}
		
		for(int i=65;i<65+number;i++){
			arr4[y]=i;
			y++;
		}
		while(flag!=0){
			int option=0;
			who_vs_who(option);
			int winning[12][12];
			int winning2[12][12];
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (User1(X) vs. User2(O))			
			if(option==1){
				cout<<endl;
				winning[12][12]=fill_zero(winning,number);
				winning2[12][12]=fill_zero(winning2,number);
				
				User_vs_User(winning,winning2,arr3,arr4,flag,number);	
			}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////  (User vs computer)					
			else if(option==2){
				cout<<endl;
				winning[12][12]=fill_zero(winning,number);
				winning2[12][12]=fill_zero(winning2,number);
				
				User_vs_Computer(winning,winning2,arr3,arr4,flag,number);
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////				
			else{
				cout<<endl<<"invalid option."<<endl;
				cout<<"Please select again."<<endl;
			}}
	return;
}



