// Sample program for Minimax Algorithm.
// Raviteja .. rationalScripts.com
// Programming is Magic .. :D

// Reference from GeekforGeeks Minimax Algorithm
#include<iostream>
using namespace std;

// Depth says the Current depth of the miniMax algorithm
// Node Index says the node under consideration
// isMax says whether we need to go by min or max couting

int maxx(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int minx(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

int miniMax(int depth,int nodeIndex,bool isMax,int height,int *input){
	if(depth == height){
		return input[nodeIndex];
	}
	if(isMax){
		return maxx(miniMax(depth+1,nodeIndex*2,false,height,input),miniMax(depth+1,nodeIndex*2 + 1,false,height,input));
	}else{
		return minx(miniMax(depth+1,nodeIndex*2,true,height,input),miniMax(depth+1,nodeIndex*2 + 1,true,height,input));
	}
}

int main(void){
	int input[8] = {10,8,9,7,3,4,6,5}; // Set under our consideration
	int height = 3; // log2 size of the input array
	int result = miniMax(0,0,true,height,input);
	cout<<"Result :"<<result<<endl;
	return 0;
}