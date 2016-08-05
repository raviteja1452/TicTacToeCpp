#include<iostream>
using namespace std;

// We are magicians
// Evaluation Function used in TicTacToe Game
// Raviteja Bejgum .. ..  RationalScripts
// Reference .. GeekforGeeks

int evaluate(char board[3][3]){
	for(int i=0;i < 3;i++){
		if((board[i][0] != '_') && (board[i][0]==board[i][1]) && (board[i][2]==board[i][1])){
			if(board[i][0] == 'x'){
				return 10;		
			}else if(board[i][0] =='o'){
				return -10;
			}
		}
	}
	for(int i=0;i < 3;i++){
		if((board[0][i] != '_') && (board[0][i]==board[1][i]) && (board[2][i]==board[1][i])){
			if(board[0][i] == 'x'){
				return 10;		
			}else if(board[1][i] =='o'){
				return -10;
			}
		}
	}
	if((board[0][0] != '_') && (board[0][0]==board[1][1]) && (board[2][2]==board[1][1])){
		if(board[0][0] == 'x'){
			return 10;		
		}else if(board[0][0] =='o'){
			return -10;
		}
	}
	if((board[0][2] != '_') && (board[0][2]==board[1][1]) && (board[2][0]==board[1][1])){
		if(board[0][2] == 'x'){
			return 10;		
		}else if(board[0][2] =='o'){
			return -10;
		}
	}
	return 0;
}
int main(void){
	// Considering TicTacToe is a 3*3 board, taking a char 3*3 array;
	char board[3][3] ={
		{'x','o','x'},
		{'_','x','_'},
		{'x','_','_'}
	};
	int value = evaluate(tboard);
	cout<<"The Value of this board :"<<value<<endl;
	return 0;
}