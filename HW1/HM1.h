//YunusEmreGeyik-1801042635
#ifndef HM1
#define HM1

void take_board_size(int &number);
void first_board_view(int number,int &t);
void who_vs_who(int &option);
void User_vs_User(int winning[12][12],int winning2[12][12],int arr3[12],char arr4[12],int &flag,int number);
void User_vs_Computer(int winning[12][12],int winning2[12][12],int arr3[12],char arr4[12],int &flag,int number);
int fill_zero(int arr[12][12],int number);
void make_board();		


#endif