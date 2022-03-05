//YunusEmreGeyik-1801042635
#ifndef HM3
#define HM3
#include <string>
#include <vector>

enum CellState {dot = 0, cross =1, circle =2};

class Hex{
private:
	class Cell{
		public:	
			Cell();
			int cell;
			int row;
			void setCell(int Newcell);
			void setRow(int Newrow);
			int getCell()const;
			int getRow()const;
			void setter(int x);
		};
public:	
	Hex();
	Hex(int arr5[100],int arr6[100],int arr7[100],int arr8[100]);
	
	std::vector<std::vector<Cell>>hexCells;
	
	static int a,b,c,d,hold1,hold2,hold3,hold4,hold5;
	int arr5[100],arr6[100],arr7[100],arr8[100];
	int number;
	
	static int Marked(int f,int l); 		//for the marked cell
	int Current_With(int x)const;   		//Current with of game table
	int Current_height(int y)const;  		//Current height of game table
	void Current_board();            		//for Current game table
	int Game_End(int r);					//for the find who won the Hex game
	void control(int &i,int &j); 			//inline function
	bool compare(Hex object);				//to compare the first game with the second game.
	void playGame(int &option);				//for determine size of game board and Game type
	void load(std::string file_name,int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &num,int &num2,int &f,int &l,int &who_vs_who);
	void save(std::string file_name,char arr[7],int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &number,int f,int l,int wch_user,int who_vs_who);
	void play(int number2,int num3); 				//for User 
	void play(); 									//for Computer
	void menu();
};

#endif