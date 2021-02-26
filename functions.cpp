
#include <iostream>
#include "functions.h"

using namespace std;



void fill_boolean_false(bool arr[][12]){ //fills the inside of the array
		
		for(int i=0;i<12;i++)
			for(int j=0;j<12;j++)
					arr[i][j]=false;
	
}

int controller(char board[][12],int x,int y,int size){ // checks new move if it's inside the map
	
	if( x<size && 0<=x && y<size && 0<=y){
			if(board[x][y]=='.' ){
				return 1;
			}
				
			else
			{
				
				return 2;
			}
					
	}
	
	else 
				
		return 0;	
	
	
}

void printBoard_align_letter(char board[][12],int size){ // prints tables letter
	
	char ch;
	int counter=0;
	
	cout<<endl;
			
	while(size>counter){
		ch=counter+97;
		cout<<" "<<ch; 
		counter++;
	}	
	
	cout<<endl;
	
}

void printBoard_Nums_data(char board[][12],int size){ // prints the data in the board
		
		int i,j,k;
			
		for (i=0;i<size;i++){
		cout<<i+1;
		if(i>8)
			for(k=1;k<i;k++)
				cout<<" ";
		else
			for(k=0;k<i;k++)
				cout<<" ";			
		
		for(j=0;j<size;j++)
			cout<<" "<<board[j][i];				
		cout<<endl;
		}
}

void printBoard_fill_dot(char board[][12],int size){ //prints dots 
	
	int i,j;
		for (i=0;i<size;i++)
			for(j=0;j<size;j++)
				board[i][j]='.';
}

void printBoard(char board[][12],int size){ // general print board function
	

	printBoard_align_letter(board,size);
	printBoard_Nums_data(board,size);

}

int take_board_size(int max_board_size,int min_board_size){ //takes board size from user 
	
	int size;
	
	cout<<"Welcome to Hex Game!Please Enter 6 map size 6 to 12 to start game."<<endl;
	
	while(1){
	cin>>size;
	
	if(size<=Max_Board_Size && size>=Min_Board_Size)
		return size;
	
	else
		cout<<"Wrong!!! Please Enter a valid number 6 map size 6 to 12!"<<endl;	
			
	}

}

void take_adress(int adress[2]){ // takes move adress from user 
	
	
		int ch,num;
		char temp;
		
		cin>>temp;
		cin>>num;
		ch=temp-97;
		num--;

		adress[0]=ch;
		adress[1]=num;
		
	
	}
	
	

void to_upper_case(char board[][12], int user ,int x,int y,bool is_visited[][12],int size){ // enlarges the letters of the winner when user win
	
	
	
	char ch;
	char ch_small_letter;
	
	if(user==0){
		
		ch='X';
		ch_small_letter='x';
		
	}
		
	
	else if(user==1) {
		ch='O';
		ch_small_letter='o';
	}
		
	else 
		return;
	
	
	if(board[x][y]==ch_small_letter && is_visited[x][y]==true){  //progresses recursively from the correct starting point
		board[x][y]=ch;
		is_visited[x][y]==false;
	
		if(x+1<size && board[x+1][y]==ch_small_letter )    //searching right way
					to_upper_case(board,user ,x+1,y,is_visited,size); 	
			
		if(x+1<size && 0<y && board[x+1][y-1]==ch_small_letter )   //searching right down way
					to_upper_case(board,user ,x+1,y-1,is_visited,size);
		
		if(y+1<size && board[x][y+1]==ch_small_letter  ) // searching up way
					to_upper_case(board,user ,x,y+1,is_visited,size);
	
		if(y+1<size && 0<x && board[x-1][y+1]==ch_small_letter ) //searching left up way
					to_upper_case(board,user ,x-1,y+1,is_visited,size);
		
		if(0<y && board[x][y-1]==ch_small_letter   ) //searching down way 
					to_upper_case(board,user,x,y-1,is_visited,size);
		
		if(0<y && board[x-1][y]==ch_small_letter  ) //searching left way
					to_upper_case(board,user,x-1,y,is_visited,size);
			
							
}	
		
	}
		

int take_user_or_computer(){ // for user to user or user to computer 
	
	int select=0;	
	cout<<"Please enter For  User 1 vs User 2 : 1"<<endl;
	cout<<"Please enter  For User vs Computer : 2"<<endl;

	while(1){
		
		cin>>select;
		
		if(select!=1 &&  select!=2)
		cout<<"Wrong!!! Please Enter a valid selection 1 or 2 !"<<endl;	
		
		else 
			return select;

	}
	
	
}

void user_play_with_computer(char board[][12],int user,int size){ // controls the mechanism when playing with the computer
	
	int control,adress[2],ch,num;
		
			while(1){
			
				
					if(user==0){
						take_adress(adress);
						ch=adress[0];
						num=adress[1];
						control=controller(board,ch,num,size);
						
						if(control==1){
								board[ch][num]='x';								
								break;
						}
						
						else 
							cout<<"Invalid choice Try again!"<<endl;			
					}
					
							
					else if(user==1){
							
							computer_play(board,size,size/2,0);
							break;
					}
					
						
				}
}

void user_play_with_user(char board[][12],int user,int size){ //controls the mechanism when playing with the user
	
	
 int control,adress[2],ch,num;
		
			while(1){
				
				take_adress(adress);
				ch=adress[0];
				num=adress[1];
				
				control=controller(board,ch,num,size);
				
			
				
				if(control==1){
					
					if(user==0)
						board[ch][num]='x';	
							
					else if(user==1)
							board[ch][num]='o';
							
					break;		
				}
				
				else
					cout<<"Invalid choice Try again!"<<endl;
			
			}
}
void user_play(int user,char board[][12],int size,int computer_or_user){ //determines which mode to play
	
	
		if(computer_or_user==1)
		user_play_with_user(board,user,size);
		
		else if(computer_or_user==2)		
		user_play_with_computer(board,user,size);		
		
		else 
			cout<<"Bir hata meydana geldi";
	
		
}

void check_win_User1(char board[][12],int size,int x,int y,int &flag,bool is_visited[][12]){ // controls if user 1 win 
	
	
	
		if(size==y)//controlling part
			return;
			
		
		if(x+1==size){//winner part 
		
		  	is_visited[x][y]=true;
			flag=1;
				return;
		}
			
		
	
	
		if(board[x][y]=='x' && is_visited[x][y]!=true){  // goes to every avaible drection as recursively 
			
				
				if(controller(board,x+1,y,size)==2 && board[x+1][y]=='x' ) // goes to right
				{
						is_visited[x][y]=true;
					check_win_User1(board,size,x+1,y,flag,is_visited);
				}
				
				if(controller(board,x-1,y,size)==2 && board[x-1][y]=='x' ) // goes to left
				{
						is_visited[x][y]=true;
					check_win_User1(board,size,x-1,y,flag,is_visited);
				}
				

			
				if(controller(board,x+1,y-1,size)==2 && board[x+1][y-1]=='x') //goes to up right 
				{
						is_visited[x][y]=true;
						check_win_User1(board,size,x+1,y-1,flag,is_visited);
				}
					
					
				if(controller(board,x,y-1,size)==2 && board[x][y-1]=='x'   )  // goes up
				{
						is_visited[x][y]=true;
						check_win_User1(board,size,x,y-1,flag,is_visited);
				}
						
				
				if(controller(board,x,y+1,size)==2 && board[x][y+1]=='x') // goes down
				{		is_visited[x][y]=true;
						check_win_User1(board,size,x,y+1,flag,is_visited);
					
				}		

				if(controller(board,x-1,y+1,size)==2  && board[x-1][y+1]=='x') //down left
				{
						is_visited[x][y]=true;
						check_win_User1(board,size,x-1,y+1,flag,is_visited);
				}	
								
		}

			return ;				
}

void check_win_User2(char board[][12],int size,int x,int y,int &flag, bool is_visited[][12]){ // checks if user 2 win 
	
	
	
		if(size==x)	//Controlling part 
			return;
			
		
		if(y+1==size){  // Winner part 
				is_visited[x][y]=true;
				flag=2;
				return;
		}
	
	
		

		if(board[x][y]=='o' && is_visited[x][y]!=true){ // goes to every avaible drection as recursively 
			
					
				if(controller(board,x,y+1,size)==2 && board[x][y+1]=='o')  // down right
				{		is_visited[x][y]=true;
						check_win_User2(board,size,x,y+1,flag,is_visited);
					
				}
				
				if(controller(board,x-1,y+1,size)==2  && board[x-1][y+1]=='o') //down left
				{
							is_visited[x][y]=true;
							check_win_User2(board,size,x-1,y+1,flag,is_visited);
				}	
									
				if(controller(board,x+1,y,size)==2 && board[x+1][y]=='o' ) // goes to right
				{
						is_visited[x][y]=true;
					check_win_User2(board,size,x+1,y,flag,is_visited);
				}

				
				if(controller(board,x-1,y,size)==2 && board[x-1][y]=='o' ) // goes to left
				{
						is_visited[x][y]=true;
					check_win_User2(board,size,x-1,y,flag,is_visited);
				}
			
			
			
				if(controller(board,x+1,y-1,size)==2 && board[x+1][y-1]=='o') //goes to up right 
				{
						is_visited[x][y]=true;
						check_win_User2(board,size,x+1,y-1,flag,is_visited);
				}
					
					
				if(controller(board,x,y-1,size)==2 && board[x][y-1]=='o'   )  // goes to up right
				{
						is_visited[x][y]=true;
						check_win_User2(board,size,x,y-1,flag,is_visited);
				}
	
			
			return ;
					
	}

}

void is_Game_tiedUp(char board[][12],int size,int &flag){ // checker is game is tied up
	
		int i,j;
		
		for (i=0;i<size;i++)
			for(j=0;j<size;j++)
					if(board[i][j]=='.')
							return;
							
		flag=3;
		return;					
}

void computer_play(char board[][12],int size,int x,int y){ // smart moves  as computer 
		
	
		if(board[x][y]=='.'){
			char ch=x+97;
			cout<<"\nComputer move:"<<ch<<y+1<<endl;
			board[x][y]='o';
			return;
			
		}
		

		
		
		if(board[x][y]=='o')	{
			
			if(controller(board,x,y+1,size)!=0 )
			 		return computer_play(board,size,x,y+1);
			 
			 
			if(controller(board,x-1,y+1,size)!=0 )
				 	return computer_play(board,size,x-1,y+1);
				 
			if(controller(board,x-1,y,size)!=0 )
			 		return computer_play(board,size,x-1,y);	 	
			 
			 
			
		}
		
		else if (board[x][y]=='x'){
			
			if(controller(board,x-1,y+1,size)!=0 )
				 	return computer_play(board,size,x-1,y);
			if(controller(board,x,y+1,size)!=0 )
			 		return computer_play(board,size,x,y+1);
			if(controller(board,x-1,y,size)!=0 )
			 		return computer_play(board,size,x-1,y);	 		 	 	
			
		}
			
		if(controller(board,x,y,size)!=0 )
				 	return computer_play(board,size,size/2+1,0);	

		
		
}
	
void win(char board[][12],int size,int user,int selection,int &flag){ // determines the winner and prints
		
		int i;
		bool is_visited[12][12];
		fill_boolean_false(is_visited);	
	
	if(user==0){
			
			for(i=0;i<size;i++) {
				
				check_win_User1(board,size,0, i,flag,is_visited);
				
				if(flag==1){
						cout<<"\nUser_1 Win"<<endl;
						to_upper_case(board,user,0,i,is_visited,size);
						return;
				}
				
			}
			
	}
	
		
		
		else if(user==1){
		
				for(i=0;i<size;i++) {	
				
					check_win_User2(board,size,i, 0,flag,is_visited);
					
							
						if(flag==2){
					
								if(selection==2)
									cout<<"\nComputer Win";
								else if(selection==1)
									cout<<"\nUser_2 Win";
							to_upper_case(board,user,i,0,is_visited,size);
							return;
						}
			
				}
	}
	
	return;
	
}

void initial_game(char board[][12]){ // main game function 
	
	
	int board_size,player_select,turn_num=10,counter=0,user;
	int flag=0;
	board_size=take_board_size(Max_Board_Size,Min_Board_Size);
	player_select=take_user_or_computer();
	printBoard_fill_dot(board,board_size);
	
	while (1){
		
			user=turn_num%2;
			printBoard(board,board_size);
			user_play(user,board,board_size,player_select);
			win(board,board_size,user,player_select,flag);
			turn_num++;
			
	
			if (flag>0){
				printBoard(board,board_size);
				break;
			}
				
	}
	
	
}

