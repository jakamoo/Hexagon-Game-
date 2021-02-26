
#ifndef functions
#define functions


const int  Max_Board_Size=12;
const int Min_Board_Size=6;

void fill_boolean_false(bool arr[][12]);
int controller(char board[][12],int x,int y,int size);
void printBoard_align_letter(char board[][12],int size);
void printBoard_Nums_data(char board[][12],int size);
void printBoard_fill_dot(char board[][12],int size);
void printBoard(char board[][12],int size);
void to_upper_case(char board[][12], int user ,int x,int y,int *max_step,int size);
int take_board_size(int max_board_size,int min_board_size);
void user_play(int turn_num,char board[][12],int size,int computer_or_user);
void check_win_User1(char board[][12],int size,int x,int y,int &flag,bool[][12],int &begin_point);
void check_win_User2(char board[][12],int size,int x,int y,int &flag,bool[][12]);
int is_Game_tieUp(char board[][12],int size);
void check_win(char board[][12],int size,const int x,const int y,int selection,int &flag);
void initial_game(char board[][12]);
void computer_play(char board[][12],int size,int x,int y);
void take_adress(int adress[2]);
void is_Game_tiedUp(char board[][12],int size,int *flag);
void user_play_with_user(char board[][12],int turn_num,int size);
void win(char board[][12],int size,int user,int selection);


#endif
