//YunusEmreGeyik-1801042635
#ifndef ARRAY1D_H
#define ARRAY1D_H
#include <string>
#include "Abstract.h"

namespace Abstract_Class{
/////////////////////////////////////////////1D ARRAY CLASS//////////////////////////////////////////////////////////
	class HexArray1D:public AbstractHex{
	public:
		//Big Three	
		HexArray1D(const HexArray1D &object);						//Copy Constructor 
		HexArray1D &operator=(const HexArray1D &object); 			//Copy Assignment Operator		
		~HexArray1D();												//Destructor

		explicit HexArray1D():AbstractHex(0){}														//Constructor.
		explicit HexArray1D(const int &x1=0,const int &x2=0):AbstractHex(x1,x2){}					//Constructor.
		explicit HexArray1D(const int &x1,const int &x2,const int &x3):AbstractHex(x1,x2,x3){}		//Constructor.
		
		void play(int &number2,int num3=0); 						//for User 
		void print()const ;											//Print the game board.	
		bool isEnd(const int &r=0)const ;							//The function that decides the end of the game.
		Cell play()const ; 											//for Computer
		int *score()const ;    										//score function
		void inline control(const int &i=0)const ; 					//inline function
		void reset() ;												//Function to Reset game content.
		Cell lastMove()const ;										//The function that returns the Last Move.	
		void setSize();                        						//Set new Size to Game Board
		bool operator==(const HexArray1D &object)const ;   			//operator that compare the games
		void writeFromFile(std::string file_name,char arr[7],int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &number,int f,int l,int wch_user,int who_vs_who);
		Cell operator()(const int &x,const int &y)const;			//Function that returns the given coordinate.
	private:
		Cell *hexCells=nullptr;                                     //HexArray1D 1D Array.
	};
}
#endif	