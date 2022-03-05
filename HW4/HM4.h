//YunusEmreGeyik-1801042635
#ifndef HM4
#define HM4
#include <string>



enum CellState {dot = 0, cross =1, circle =2};    

class Hex{
public:	
	class Cell{
		public:	
			explicit Cell():cell(0),row(0){} 	/*A constructor of the nested Cell class*/
			~Cell(){};   					 	//Destructor for the inner Cell class
			void setCell(const int &cell=0);
			void setRow(const int &row=0);
			int getCell()const;
			int getRow()const;
			void setter(const int &x=0);
		private:
			int cell;
			int row;
		};
	
	//Big Three	
	explicit Hex(const Hex &object);		 //Copy Constructor 
	Hex &operator=(const Hex &object);		 //Copy Assignment Operator		
	~Hex();									 //Destructor
	
	explicit Hex(const int &x1=0,const int &x2=0);             //Constructor
	explicit Hex(const int &x1,const int &x2,const int &x3):number(x1),number_marked(x3){}   //Constructor
	explicit Hex():number(0),number_marked(0),hold5(0){}      //Constructor
	
	void setNumber(const int &newNumber=0);		//set for the size of board.
	int getNumber () const;						//get for the size of board.
  
	int getNumber_Marked () const;  			//get for the size of the number_of_marked.
	void setNumber_Marked(const int &newNumber=0);	//set for the size of the number_of_marked.

	int getHold5 () const;						//get for the size of hold5 variable.
	void setHold5(const int &hold5=0);			//set for the size of hold5 variable.

	int getSize () const;						//get for the size of array.
	void setSize(const int &size=0);				//set for the size of array.					
	
	static int Marked(const int &f=0,const int &l=0);
	int Current_With(const int &x=0)const;              //for the current board with
	int Current_height(const int &y=0)const;   		//for the current board height
	void Current_board()const;									
	int Game_End(const int &r=0)const;
	void inline control(const int &i=0,const int &j=0)const; 		//inline function
	bool operator==(Hex &object)const;   						//operator that compare the games
	void playGame(int &option);      
	void load(const std::string &file_name)const;
	void save(const std::string &file_name)const;
	void play(int &number2,int num3=0); 				//for User 
	Cell play()const; 								//for Computer
	void menu(int &x2);
	void operator--();  						//pre decrement
	void operator--(int y=0);  					//post decrement
	int *score()const;    						//score function
	
	friend std::ofstream &operator <<(std::ofstream &output,const Hex &obj);   //for writing to the file 
	friend std::ifstream &operator >>(std::ifstream &input,const Hex &obj);	 //for reading to the file
	friend std::ostream &operator << (std::ostream &out, const Hex &obj);      //for the screen prints

private:
	static int b,c,d,f,l,e,counter17,ctr3,ctr4,num,num2,ctr5;
	static int hold1,hold2,hold3,hold4,wch_user,who_vs_who,count18;
	static int *arr5,*arr6,*arr7,*arr8;
	static char *arr;
	int number,number_marked,hold5,size;
	Cell ** hexCells=nullptr;                //two dimensional array
};

#endif