#include "fun.h"
#include <map>
#include <utility> //used for pair
/* your includes here */

std::map<std::pair<int,int>, int> calls; 

unsigned int fun(unsigned int x, unsigned int y) {
	/* your code here */

	//I will be using a map for this question, 1 part holds the result and the other the inputs x and y
	std::pair<int,int> args = std::make_pair(x,y); 

	if(calls.find(args) != calls.end()){ 
		//will find if the pair is in the map and return the argument, no redundant calls!
		return calls[args]; 
	}
	
	int result;
	
	//cases given in question
	
	if(x == 0 && y == 0){
		result = 1; 
	}
	else if(x == 0 && y != 0){
		result = y+1; 
	}
	else if(x != 0 && y == 0){
		result = fun(x-1, 1); 
	}
	else{
		result = fun(x-1,fun(x-1, y-1)); 
	}

	calls[args] = result; 

	return result; /* don't forget to change the return value */
}

/* your helper function here if you have any */
/*

Resources used: 
	
	EC327 Homework 8, problem 4 for maps
	Chatgpt to give me std::pair syntax and library to store (x,y)
	
*/