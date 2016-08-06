// Love Programming, It loves you back.. with probability of 1
// Rational Scripts
// Be rational .. 
// Raviteja Bejgum
// Alpha Beta Pruning Example

#include<iostream>
using namespace std;

// Alpha Beta pruning is nothing but an improvisation of Minimax algorithm to reduce the number of recursive searches.
// Along with the mentioned parameters in Minimax, we also pass Alpha, Beta as parameters in alpha_beta pruning..

// Alpha is nothing but Best value of the  maximizer currently can guarentee at that level at that point of time.
// Alpha is inititalized to -Infinity

// Beta is nothing but Best value of the minimizer currently can gurantee at that level at that point of time.
// Beta is initialized to +Infinity
// Algorithm is not just understood by its program, go through the flow of the program to understand the benfit of Alpha - Beta Pruning


// Maximum Function

int maxx(int a, int b){
	if(a > b){
		return a;
	}
	return b;
}

// Minimum Funtion

int minx(int a,int b){
	if(a < b){
		return a;
	}
	return b;
}
// Minimax Function with Alpha Beta Pruning involved.

int miniMax(int rational[8],bool isMax,int depth,int nodeIndex,int alpha,int beta){
	if(depth == 3){
		return rational[nodeIndex];
	}
	if(isMax){
		int maxVal = -1000;
		for(int i = 0;i < 2;i++){
			int val = miniMax(rational,false,depth+1,2*nodeIndex + i,alpha,beta);
			maxVal = maxx(val,maxVal);
			alpha = maxx(maxVal,alpha);
			// Alpha Beta Pruning Step
			// if the beta calculated from parent is less than alpha of right child,we dont need to dig deeper.
			// Hard to understand by words, Imagine how it works, they we can understand.
			if(beta <= alpha)
				break;
		}
		return maxVal;
	}else{
		int minVal = 1000;
		for(int i = 0;i < 2;i++){
			int val = miniMax(rational,true,depth+1,2*nodeIndex+i,alpha,beta);
			minVal = minx(val,minVal);
			beta = minx(minVal,beta);
			// Alpha Beta pruning step
			// if Alpha of the parent is greater than the beta calculated from child up to now, we don't need to dig deeper
			// because minVal can be less than or equal to beta, but this will not change the maxVal of parent anyway.
			if(beta <= alpha)
				break;
		}
		return minVal;
	}
}

//Main Function
int main(void){
	int rational[8] = {3, 5, 6, 9, 1, 2, 10, 8};
	int alpha = -1000;
	int beta = 1000;
	int answer = miniMax(rational,true,0,0,alpha,beta);
	cout<<answer<<endl;
	return 0;
} 
