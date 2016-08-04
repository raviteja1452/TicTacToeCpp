// Made in Love with Programming 
// Raviteja Bejgum .. RationalScripts
// TicTacToe Single Player, using AI (MiniMax Algorithm)
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

// minx function

int minx(int a,int b){
	if(a < b){
		return a;
	}
	return b;
}

//Print board
void printBoard(char board[3][3]){
	cout<<"\n\n\n";
	for(int i = 0;i < 3; i++){
		cout<<"          | "<<board[i][0]<<" | "<<board[i][1]<<" | "<<board[i][2]<<" | \n"<<endl;
	}
	cout<<"\n\n\n";
}

// Evaluate Function or Validate Function 
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
			}else if(board[0][i] =='o'){
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
		return score-depth;
	}
	if(score == -10){
		return score+depth;
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
					bestVal = maxx(bestVal,miniMax(board,depth + 1 ,false));
					//cout<<"In Max "<<bestVal<<endl;
					//printBoard(board);
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
					bestVal = minx(bestVal,miniMax(board,depth + 1 ,true));
					//cout<<"In Min "<<bestVal<<endl;
					//printBoard(board);
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
				//cout <<i<<" "<<j<<" "<<moveVal<<endl;
				if(moveVal > bestVal){
					row = i;
					col = j;
					bestVal = moveVal;
				}
			}
		}
	}
}

// game board
void gamePlay(char board[3][3]){
	for(int i =0 ;i < 3;i++){
		for(int j =0;j< 3;j++){
			board[i][j]='_';
		}
	}
	int row,col;
	printBoard(board);
	int counter = 0;
	while(!noMovesLeft(board)){
		counter++;
		if(counter%2 == 1){
			cout<<" --> USER: Select a row and coloumn to play your piece :";
			cin>>row>>col;
			if(board[row][col]=='_'){
				board[row][col] = 'o';
			}else{
				cout<<" -->USER: Enter in empty locations <<endl";
				counter--;
			}
		}else{
			findBestMove(board,row,col);
			board[row][col] = 'x';
			cout<<" -->COMPUTER: Selected row : "<<row<<" and coloumn : "<<col<<endl;
		}
		printBoard(board);
		if(evaluate(board) == 10){
			cout<<"\n\n         Better Luck next time\n\n         ---- Computer is the Winner ----"<<endl;
			break;
		}else if(evaluate(board) == -10){
			cout<<"\n\n         Hurray\n\n         ---- U won ----\n\n\n        **** But Your Princes is in other Castle *****"<<endl;
			break;
		}
	}
	if(noMovesLeft(board)){
		cout<<"  Uff!! Try Again ...."<<endl;
	}
}
// Main Function
int main(void){
	char board[3][3];
	// Game Play Controls the entire play
	gamePlay(board);
	return 0;
}