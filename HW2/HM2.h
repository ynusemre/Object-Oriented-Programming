//YunusEmreGeyik-1801042635
#ifndef HM2
#define HM2
#include <string>

enum CellState {dot = 0, cross =1, circle =2};
int fill_zero(int arr[12][12],int number);
void load(std::string file_name,int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &num,int &num2,int &f,int &l,int &who_vs_who);
void save(std::string file_name,int winning[12][12],int winning2[12][12],char arr[7],int arr5[100],int arr6[100],int arr7[100],int arr8[100],int &number,int f,int l,int wch_user,int who_vs_who);
void take_board_size(int &number);
void first_board_view(const int number,int &t);
void who_vs_who(int &option);
void User_vs_User(int arr5[100],int arr6[100],int arr7[100],int arr8[100],int winning[12][12],int winning2[12][12],int arr3[12],char arr4[12],int &flag,int number,int &nbr,int &nbr2,int &f,int &l,int &h);
void User_vs_Computer(int arr5[100],int arr6[100],int arr7[100],int arr8[100],int winning[12][12],int winning2[12][12],int arr3[12],char arr4[12],int &flag,int number,int nbr,int nbr2,int f,int l);
void make_board();		


#endif



