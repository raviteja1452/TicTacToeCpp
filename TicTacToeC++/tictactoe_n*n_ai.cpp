// Made in Love with Programming 
// Raviteja Bejgum .. RationalScripts
// TicTacToe Single Player, using AI (MiniMax Algorithm)
// Reference : GeekforGeeks
// Be Rational..
// This is just an extension of tictactoe_ai.cpp programming, 
// In stead of using a normal miniMax algorithm, we here are using Alpha Beta Pruned miniMax Algorithm
// This makes the search ever more faster.

// Look at alphabeta_pruning.cpp for understanding Alpha Beta pruning in miniMax algorithm..

// You can't find a big difference with 3*3 tictactoe, but with increase in size of tictactoe , it makes a signigicant impact.

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
void printBoard(char board[5][5],int size){
	cout<<"\n\n\n";
	for(int i = 0;i < size; i++){
		cout<<"          | ";
		for(int j = 0;j<size;j++){
			cout<<board[i][j]<<" | ";
		}
		cout<<"\n";
	}
	cout<<"\n\n\n";
}

// Evaluate Function or Validate Function 
int evaluate(char board[5][5],int size){

	// Checking Rows
	//cout<<"In Evaluate Function";
	for(int i=0;i < size;i++){
		if(board[i][0] != '_'){
			int j = 0;
			for(j = 0;j < size - 1;j++){
				if(board[i][j]!=board[i][j+1]){
					break;
				}
			}
			if(j == size - 1){
				if(board[i][0] == 'x'){
					return 10;		
				}else if(board[i][0] =='o'){
					return -10;
				}
			}
		}
	}

	// Checking Columns
	for(int i=0;i < size;i++){
		if(board[0][i] != '_'){
			int j = 0;
			for(j = 0;j < size - 1;j++){
				if(board[j][i]!=board[j+1][i]){
					break;
				}
			}
			if(j == size - 1){
				if(board[0][i] == 'x'){
					return 10;		
				}else if(board[0][i] =='o'){
					return -10;
				}
			}
		}
	}
	
	// Checking Diagonals 
	if(board[0][0] != '_'){
		int i = 0;
		for(i = 0;i < size - 1;i++){
			if(board[i][i] != board[i+1][i+1]){
				break;
			}
		}
		if(i == size - 1){
			if(board[0][0] == 'x'){
				return 10;		
			}else if(board[0][0] =='o'){
				return -10;
			}
		}	
	}

	// Checking Second Diagonal

	if(board[0][size - 1] != '_'){
		int i = 0;
		for(i = 0;i < size - 1;i++){
			if(board[i][size - 1 -i] != board[i+1][size-2-i]){
				break;
			}
		}
		if(i == size - 1){
			if(board[0][0] == 'x'){
				return 10;		
			}else if(board[0][0] =='o'){
				return -10;
			}
		}	
	}
	return 0;
}

// Function checking if any move left

bool noMovesLeft(char board[5][5],int size){
	for(int i = 0;i < size;i++){
		for(int j = 0;j < size;j++){
			if(board[i][j] == '_'){
				return false;
			}
		}
	}
	return true;
}

// Minimax function for finding scores of each possible step
// Alpha Beta Pruned minMax function
int miniMax(char board[5][5],int depth, bool isMax,int alpha,int beta,int size){
	int score = evaluate(board,size);
	if(score == 10){
		return score - depth;
	}
	if(score == -10){
		return score + depth;
	}
	if(noMovesLeft(board,size)){
		return 0;
	}
	if(isMax){
		int bestVal = -1000;
		for(int i = 0; i < size;i++){
			for(int j = 0;j < size;j++){
				if(board[i][j] == '_'){
					board[i][j] = 'x';
					int val = miniMax(board,depth + 1 ,false,alpha,beta,size);
					bestVal = maxx(bestVal,val);
					alpha = maxx(bestVal,alpha);
					//cout<<"In Max "<<bestVal<<endl;
					//printBoard(board);
					board[i][j] = '_';
					if(beta <= alpha)
						break;
				}
				if(beta <= alpha)
					break;
			}
		}
		return bestVal;
	}else{
		int bestVal = 1000;
		for(int i = 0; i < size;i++){
			for(int j = 0;j < size;j++){
				if(board[i][j] == '_'){
					board[i][j] = 'o';
					int val = miniMax(board,depth + 1 ,true,alpha,beta,size);
					bestVal = minx(bestVal,val);
					beta = minx(bestVal,beta);
					//cout<<"In Min "<<bestVal<<endl;
					//printBoard(board);
					board[i][j] = '_';
					if(beta <= alpha)
						break;
				}
				if(beta <= alpha)
					break;
			}
		}
		return bestVal;
	}

}

// Finds the Best Move
void findBestMove(char board[5][5],int &row,int &col,int size){
	int bestVal = -1000;
	int alpha = -1000;
	int beta = 1000;
	for(int i = 0;i < size; i++){
		for(int j =0;j < size;j++){
			if(board[i][j] == '_'){
				board[i][j] = 'x';
				int moveVal = miniMax(board,0,false,alpha,beta,size);
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
void gamePlay(char board[5][5],int size){
	for(int i =0 ;i < size;i++){
		for(int j =0;j< size;j++){
			board[i][j]='_';
		}
	}
	int row,col;
	printBoard(board,size);
	int counter = 0;
	while(!noMovesLeft(board,size)){
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
			findBestMove(board,row,col,size);
			board[row][col] = 'x';
			cout<<" -->COMPUTER: Selected row : "<<row<<" and coloumn : "<<col<<endl;
		}
		printBoard(board,size);
		int eval = evaluate(board,size);
		if( eval == 10){
			cout<<"\n\n         Better Luck next time\n\n         ---- Computer is the Winner ----"<<endl;
			break;
		}else if(eval == -10){
			cout<<"\n\n         Hurray\n\n         ---- U won ----\n\n\n        **** But Your Princes is in other Castle *****"<<endl;
			break;
		}
	}
	if(noMovesLeft(board,size)){
		cout<<"  Uff!! Try Again ...."<<endl;
	}
}
// Main Function
int main(void){
	char board[5][5];
	int turn = 1;
	while(turn!= 0){
		int size;
		// Dont try running above 3, its of super huge complexity 
		// 4*4 is of 10^16 and 5*5 is of 10^25 complexity
		cout<<"---- Enter the size of the board (3 to 5) which you want to play:";
		cin>>size;
		if(size > 5){
			size = 3;
		}
		// Game Play Controls the entire play
		gamePlay(board,size);
		cout<<"----Press 1 to play again\n----Press 0 to quit\n";
		cin>>turn;
	}
	return 0;
}