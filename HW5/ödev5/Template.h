//YunusEmreGeyik-1801042635
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <string>
#include "Abstract.h"

namespace Abstract_Class{
////////////////////////////////////////////////TEMPLATE CLASS/////////////////////////////////////////////////////////////
	template<template<typename...> class T>
	class HexAdapter :public AbstractHex{
	public:
		//Big Three	
		HexAdapter(const HexAdapter<T> &object);						//Copy Constructor 
		HexAdapter<T> &operator=(const HexAdapter<T> &object); 			//Copy Assignment Operator		
		~HexAdapter();													//Destructor

		explicit HexAdapter():AbstractHex(0){}													//Constructor.
		explicit HexAdapter( int x1=0, int x2=0):AbstractHex(x1,x2){}							//Constructor.
		explicit HexAdapter(const int &x1,const int &x2,const int &x3):AbstractHex(x1,x2,x3){}	//Constructor.

		void inline control(const int &i=0,const int &j=0)const; 
		void print()const ;										//Print the game board.
		bool isEnd(const int &r=0)const ;						//The function that decides the end of the game.
		void play(int &number2,int num3=0); 					//for User 
		Cell play()const ; 										//for Computer
		int *score()const ;										//score function.	
		void reset() ;											//Function to Reset game content.
		void setSize();                        					//Set new Size to Game Board
		Cell lastMove()const ;									//The function that returns the Last Move.
		Cell operator()(const int &x,const int &y)const;		//Function that returns the given coordinate.	
		void writeFromFile(std::string file_name,char arr[7],int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &number,int f,int l,int wch_user,int who_vs_who);
		bool operator==(const HexAdapter<T> &object)const;			//operator that compare the games.

	private:
		T <T<Cell>> hexCells;								//HexAdapter Class Template Variables.				
	};
}
#endif	