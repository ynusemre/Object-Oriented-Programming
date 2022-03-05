//YunusEmreGeyik-1801042635
#ifndef ABSTRACT_H
#define ABSTRACT_H
#include <string>
enum CellState {dot = 0, cross =1, circle =2};  

namespace Abstract_Class{
/////////////////////////////////////////////ABSTRACT CLASS//////////////////////////////////////////////////////////
	class AbstractHex{
	protected:
		static int b,c,d,f,l,e,counter17,ctr3,ctr4,num,num2,ctr5,h1,h2,h3,h4;
		static int hold1,hold2,hold3,hold4,wch_user,who_vs_who,count18;
		static char *arr;
		int *arr5,*arr6,*arr7,*arr8;
		int number,number_marked,hold5,size;
		std::string file_name;
		char *APtr;
	public:
		class Cell{
			public:	
				explicit Cell():cell(0),row(0){}   /*A constructor of the nested Cell class*/
				~Cell(){};                            //Destructor for the inner Cell class
				void setCell(const int &cell=0);
				void setRow(const int &row=0);
				int getCell()const;
				int getRow()const;
				void setter(const int &x=0);
			private:
				int cell;
				int row;
			};

		class OperatorMistake{
			public:
				std::string mistake;
				OperatorMistake(std::string mistake):mistake(mistake){}
		};
		//Big Three
		explicit AbstractHex(const AbstractHex &object);					//Copy Constructor 
		AbstractHex &operator=(const AbstractHex &object); 					//Copy Assignment Operator		
		virtual ~AbstractHex();												//Destructor
			
		explicit AbstractHex(const int &x1=0,const int &x2=0);
		explicit AbstractHex(const int &x1,const int &x2,const int &x3):number(x1),size(x2),number_marked(x3){}
		explicit AbstractHex():number(0),size(0),number_marked(0){}
			
		void setNumber(const int &newNumber=0);                     //set for the size of board.
		int getNumber () const;              						//get for the size of board.

		int getNumber_Marked () const;                               //get for the size of the number_of_marked.
		void setNumber_Marked(const int &newNumber=0);               //set for the size of the number_of_marked.

		int getHold5 () const;                                       //get for the size of hold5 variable.
		void setHold5(const int &hold5=0);							//set for the size of hold5 variable.

		int getSize () const;										//get for the size of array.
		void setsize(const int &size=0); 							//set for the size of array.
		
		std::string getFile_Name () const;							//get for the name of file.
		void setFile_Name(const std:: string &file_name);           //set for the name of file.

		int geth3 () const;											//get for the hold last coordinate's row.
		int geth4 () const;											//get for the hold a coordinate's column.

		char* getPtr()const;							//function that returns the pointer holding the X and Os in the file.			
		static int numberofMoves(const int &f=0,const int &l=0);      //The function that returns the number of moves made.
		int Current_With(const int &x=0)const;                       //for the current board with
		int Current_height(const int &y=0)const;                     //for the current board height
		bool operator==(const AbstractHex &object)const ;   		//operator that compare the games
		void readFromFile(int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &num,int &num2,int &f,int &l,int &who_vs_who);
		void playGame(int &option);      
		void menu(int &x2);
		void inline control(const int &i=0,const int &j=0)const; 	//inline function.
		virtual void print()const =0;									//Print the game board.
		virtual bool isEnd(const int &r=0)const =0;						//The function that decides the end of the game.
		virtual void play(int &number2,int num3=0) =0; 					//for User.
		virtual Cell play()const =0; 									//for Computer.
		virtual int *score()const =0;    								//score function.
		virtual void writeFromFile(std::string file_name,char arr[7],int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &number,int f,int l,int wch_user,int who_vs_who) = 0;
		virtual void reset() =0;										//Function to Reset game content.	
		virtual void setSize() =0;                        				//Set new Size to Game Board.
		virtual Cell lastMove()const =0;								//The function that returns the Last Move.
		virtual Cell operator()(const int &x,const int &y)const =0;		//Function that returns the given coordinate.
		AbstractHex *AbstractPtr;										//Abstract Class pointer.
	};
	bool isValid(const AbstractHex *AbstractPtr);							//Valid check for the the Game
}
#endif
