// Programming can create wonders
// Raviteja Bejgum .. RationalScripts
// minimax_evaluation 
// Evaluating the best possible next move for a computer
// Reference : GeekforGeeks
#include<iostream>
using namespace std;


// maximum function

int maxx(int a,int b){
	if(a > b){
		return a;
	}
	return b;
}
int minx(int a,int b){
	if(a < b){
		return a;
	}
	return b;
}

// Evaluate Function 
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

// Function checking if any move left

bool noMovesLeft(char board[3][3]){
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(board[i][j] == '_'){
				return false;
			}
		}
	}
	return true;
}
// Minimax function for finding scores of each possible step
int miniMax(char board[3][3],int depth, bool isMax){
	int score = evaluate(board);
	if(score == 10){
		return score - depth;
	}
	if(score == -10){
		return score + depth;
	}
	if(noMovesLeft(board)){
		return 0;
	}
	if(isMax){
		int bestVal = -1000;
		for(int i = 0; i < 3;i++){
			for(int j = 0;j < 3;j++){
				if(board[i][j] == '_'){
					board[i][j] = 'x';
					bestVal = maxx(bestVal,miniMax(board,depth +1 ,!isMax));
					board[i][j] = '_';
				}
			}
		}
		return bestVal;
	}else{
		int bestVal = 1000;
		for(int i = 0; i < 3;i++){
			for(int j = 0;j < 3;j++){
				if(board[i][j] == '_'){
					board[i][j] = 'o';
					bestVal = minx(bestVal,miniMax(board,depth + 1 ,isMax));
					board[i][j] = '_';
				}
			}
		}
		return bestVal;
	}

}

// Finds the Best Move
void findBestMove(char board[3][3],int &row,int &col){
	int bestVal = -1000;
	for(int i = 0;i < 3; i++){
		for(int j =0;j < 3;j++){
			if(board[i][j] == '_'){
				board[i][j] = 'x';
				int moveVal = miniMax(board,0,false);
				board[i][j] = '_';
				if(moveVal > bestVal){
					row = i;
					col = j;
					bestVal = moveVal;
				}
			}
		}
	}
}
// Main Function
int main(void){
	char board[3][3] ={
		{'x','o','x'},
		{'_','x','_'},
		{'o','_','o'}
	};
	int row,col;
	findBestMove(board,row,col);
	cout<<"The best possible next move is : " <<row <<" "<<col<<endl;
	return 0;
}