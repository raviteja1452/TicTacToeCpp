//
// 
//  Basic TicTacToe withOut AI
//
//  Created by raviteja1452 on 29/07/16.
//  Copyright © 2016 Raviteja Bejgum. All rights reserved.
//

#include <iostream>

using namespace std;

// Board Class
class Board{
    private:
        int winPositions[8][3]={
            {0,1,2},
            {3,4,5},
            {6,7,8},
            {0,3,6},
            {1,4,7},
            {2,5,8},
            {0,4,8},
            {2,4,6}
        };
        char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
        int winCounter = 0;
    public:
        Board(){
            
        }
        
        int printBoard(){
            char s[7];
            int j = 0;
            for(int i = 0;i < 9;i++){
                s[j] = this->board[i];
                j = j + 1;
                s[j] = '|';
                j = j + 1;
                if(i%3==2)
                {
                    s[j] = '\0';
                    cout<<s<<endl;
                    j = 0;
                }
            }
            return 0;
        }
    
        char getBoardPosition(int pos){
            return this->board[pos];
        }
    	
    	int getWinCounter()
    	{
    		return this->winCounter;
    	}
        int setBoardPosition(int pos,char val)
        {
            if(pos >=0 && pos < 9){
                this->board[pos] = val;
                return 1;
            }
            return 0;
        }
    
        int foundWinner()
        {
            // Checking for winner
            for(int i = 0;i < 8;i++)
            {
                if(this->allEqual(i))
                {
                	this->winCounter = 1;
                    return 1;
                }
            }
            return 0;
        }
        
        int allEqual(int i){
            // Checking for Winning Positions
            if((this->board[this->winPositions[i][0]] != ' ') && (this->board[this->winPositions[i][0]] == this->board[this->winPositions[i][1]]) && (this->board[this->winPositions[i][2]] == this->board[this->winPositions[i][1]]))
            {
                return 1;
            }
            return 0;
        }
        
        int noMovesLeft()
        {
            // Checking for the Positions on the board
            for(int i = 0;i < 9;i++)
            {
                if(this->board[i] == ' ')
                {
                    return 0;
                }
            }
            return 1;
        }
        
        int gameOver()
        {
            // Checks whether the game is over or not
            return (this->foundWinner() || this->noMovesLeft());
        }
        ~Board(){
            
        }
    
};


// Player Class
class Player{
    private:
        char piece;
    public:
        Player(char piece){
            this->piece = piece;
        }
        int printPlayer(){
            cout<<"Player :"<<this->piece<<endl;
            return 1;
        }
        int move(Board *board){
            // Player move
            return this->getMove(board);
        }
        int getMove(Board * board){
            int move;
            // Player move
            cout<<this->piece<<"--> Position you want to enter your piece :";
            cin>>move;
            return this->makeMove(move,board);
        }
        int makeMove(int move,Board *board){
            // Player making a move
            if(move >= 0 && move < 9 && board->getBoardPosition(move) == ' ')
            {
                return board->setBoardPosition(move,this->piece);
            }else{
                cout<<"Do insert at positions where pieces are not inserted"<<endl;
            }
            return 0;
        }
        ~Player(){
        }
};


// Game class
class Game{
    private:
        Player *player_x,*player_o,*current_player;
        Board *board;
    public:
        Game(){
            // Creating TicTacToe Board
            board = new Board();
            // Creating Players
            player_x = new Player('x');
            player_o = new Player('o');
            // Setting Current Player
            current_player = player_x;
        }
        int start(){
            // Handle, Where the TicTacToe Game Starts
            while(!this->board->gameOver()){
                // We will run the game till the game over is not over
                // Asking for Player to make a move
                this->board->printBoard();
                if(this->current_player->move(this->board)){
                    this->swapPlayer();
                }
            }
            return this->atGameEnd();
        }
        int swapPlayer(){
            if(this->current_player==this->player_x){
                this->current_player = this->player_o;
            }else{
                this->current_player = this->player_x;
            }
            return 0;
        }
        int gameOver(){
            return this->board->gameOver();
        }
        int atGameEnd(){
        	if(this->board->getWinCounter())
        	{
        		this->swapPlayer();
        		cout<<"Winner is :";
        		this->current_player->printPlayer();
        		cout<<"Game Ended"<<endl;	
        	}else{
        		cout<<"All moves Completed :( .. Game Ended"<<endl;
        	}
            
            return 1;
        }
        ~Game(){
            
        }
};


// Main 
int main(int argc, const char * argv[]) {
    // Hello
    cout << "Hello .. Welcome to TicTacToe in C++!\n";
    // Creating an TicTacToe Game Object
    Game *game  = new Game();
    // Starting Game
    game->start();
    return 0;
}
