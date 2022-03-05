#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

#include "Template.cpp"
#include "Template.h"
#include "Vector.h"
#include "HexArray1D.h"
#include "Abstract.h"

using namespace Abstract_Class;
using namespace  std;

int main(){
	int x1=0,x2=0,x3=100;
	

	
	AbstractHex *arr[8];
	int option=0,counter=0;
	int counter1=0,counter2=0,counter3=0,counter4=0;

	arr[0]=new HexVector(x1,x3);
	arr[1]=new HexArray1D(x1,x3);
	arr[2]=new HexVector(x1,x3);
	arr[3]=new HexArray1D(x1,x3);
	

	arr[4]=new HexAdapter <deque>(x1,x3);
	arr[5]=new HexAdapter <vector>(x1,x3);
	arr[6]=new HexAdapter <deque>(x1,x3);
	arr[7]=new HexAdapter <vector>(x1,x3);


	HexVector *game1=(HexVector*)arr[0];
	HexArray1D *game2=(HexArray1D*)arr[1];
	HexVector *game5=(HexVector*)arr[2];
	HexArray1D *game6=(HexArray1D*)arr[3];
	
	HexAdapter <deque>*game3=(HexAdapter<deque>*)arr[4];
	HexAdapter <vector>*game4=(HexAdapter<vector>*)arr[5];
	HexAdapter <deque>*game7=(HexAdapter<deque>*)arr[6];
	HexAdapter <vector>*game8=(HexAdapter<vector>*)arr[7];

	while(true){
		if(counter==2){
			break;
		}
		cout<<endl<<"Which class do you want to play with?"<<endl;
		cout<<"1.Vector Class"<<endl;
		cout<<"2.1D Array Class"<<endl;
		cout<<"3.Deque Template Class"<<endl;
		cout<<"4.Vector Template Class"<<endl;

		cout<<endl<<"Option: ";
		cin>>option;

		if (!(option)){
			cout <<endl<<"Please enter numbers only."<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}

		if(option==1){
			if(counter1==1){
				game5->menu(x2);
				counter++;
				counter1++;
			}

			if(counter1==0){
				game1->menu(x2);
				counter++;
				counter1++;
			}	
		}
		else if(option==2){
			if(counter2==1){
				game6->menu(x2);
				counter++;
				counter2++;
			}
			if(counter2==0){
				game2->menu(x2);
				counter++;
				counter2++;
			}
		}
		
		else if(option==3){
			if(counter3==1){
				game7->menu(x2);
				counter++;
				counter3++;	
			}	
			if(counter3==0){
				game3->menu(x2);
				counter++;
				counter3++;
			}		
		}
		else if(option==4){
			if(counter4==1){
				game8->menu(x2);
				counter++;
				counter4++;
			}	
			if(counter4==0){
				game4->menu(x2);
				counter++;
				counter4++;
			}	
		}
		else{
			cerr<<endl<<"!!!!invalid option!!!!"<<endl;
			cerr<<"!!!!Please select again!!!!"<<endl;
		}
	}
		

	if(counter1==2){
		bool Result=*arr[0]==*arr[2];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter2==2){
		bool Result=*arr[1]==*arr[3];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter3==2){
		bool Result=*arr[4]==*arr[6];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter4==2){
		bool Result=*arr[5]==*arr[7];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter1==1 && counter2==1){
		bool Result=*arr[0]==*arr[1];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter1==1 && counter3==1){
		bool Result=*arr[0]==*arr[4];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter1==1 && counter4==1){
		bool Result=*arr[0]==*arr[5];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter2==1 && counter3==1){
		bool Result=*arr[1]==*arr[4];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter2==1 && counter4==1){
		bool Result=*arr[1]==*arr[5];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	if(counter3==1 && counter4==1){
		bool Result=*arr[4]==*arr[5];

		cout<<endl<<"The result of comparing the games of two objects:"<<Result<<endl;

		if(Result==true){
			cout<<endl<<"The Games Board of two Game are equal."<<endl;
		}
		if(Result==false){
			cout<<endl<<"The Games Board of two Game are not equal."<<endl;
		}
	}
	return 0;
}