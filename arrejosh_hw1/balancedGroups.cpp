#include "balancedGroups.h"
// your includes here
#include <numeric> 
#include <algorithm> 
#include <vector>  

Assignment balancedGroups(std::vector<int> const &birthdays) {
	
	int total = 0; 
	
	for(auto birthdate : birthdays){
		total += birthdate; 
	}

	int n = birthdays.size(); 

	std::vector<std::vector<bool>> dp_table(n+1, std::vector<bool>((total/2) + 1, false)); 

	dp_table[0][0] = true; //this is the default case

	for(int i = 1; i <= n; ++i){
		int j = 0; 
		while(j <= total/2){ //goes through all possible sums 
			if(j >= birthdays[i-1]){

				//in or exclude current bday
				dp_table[i][j] = dp_table[i-1][j] || dp_table[i-1][j - birthdays[i-1]]; 
			}
			else{
				//if you dont include, copy last value
				dp_table[i][j] = dp_table[i-1][j]; 
			}
			j++;
		}
	}

	int sum_a = total/2; 

	while(sum_a>=0 && !dp_table[n][sum_a]){
		--sum_a; 
	}

	std::vector<int> ga, gb; 

	for(int i = n, j = sum_a; i > 0; i--){
		if(j >= birthdays[i-1] and dp_table[i-1][j-birthdays[i-1]]){
			ga.push_back(birthdays[i-1]); 
			j -= birthdays[i-1]; 
		}
		else{
			gb.push_back(birthdays[i-1]); 
		}
	}

	return Assignment(std::abs(total - 2 * sum_a), ga, gb); // Don't forget to change this
}

/* your helper function here if you have any */

/*

Resources used

Chatgpt for 2-d vector syntax
Tushar Roy-Coding Made Simple: Subset Sum Problem Dynamic Programming-used to understand an efficient method of solving problem
*/