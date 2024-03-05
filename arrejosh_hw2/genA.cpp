#include <iostream> 
#include <cstdlib> 
#include <vector> 
#include <map> 
#include <string.h> 

/*
resources used:

*last homework for recursion function

*/

unsigned long int genA_iter(int n){
    
    //For the iterative function ill just solve the terms as it goes


    if(n < 0){
        return EXIT_FAILURE; //n can't be negative
    }
    else if(n == 1 || n == 0){
        return 1; //A[0] & A[1] = 1
    }

    //The if else statements should remove some of the time for A[0] and A[1]

    unsigned long int a[n + 1]; //houses the A indexes
    memset(a,0,sizeof(a)); 

    a[0] = 1;
    a[1] = 1; 

    for(int i = 2; i <= n; ++i){ //starts at 2 since we have a[0] and a[1]
        for(int j = 0; j< i; ++j){
            a[i] += (a[j] * a[i - j - 1]); 
        }
    }

    return a[n]; 
}

std::map<int, unsigned long> calls; //wont make new maps when im in recurrsive function
unsigned long genA_recur(int n){
    
    /*
    For the recursive function I used the code from the last homework since I felt that maps are more effective 
    for recording different values
    */

    if(n < 0){
        return EXIT_FAILURE; 
    }
    else if(n == 0 || n == 1){ //gets rid of unnecessary calls
        return 1; 
    }

    if(calls.find(n) != calls.end()){
        return calls[n]; 
    }

    unsigned long res = 0; 

    for(int i = 0; i < n; i++){
        res += genA_recur(i) * genA_recur(n - i - 1); 
    }

    calls[n] = res; 
    return res; //A[2] = 2 for n = 3
}


/*int main(){

    int res_iter, res_recur; 
    for(int i = 0; i<=13; i++){
        res_iter = genA_iter(i); 
        std::cout << "iterate: n = " << i << " => " << res_iter << std::endl; 

        res_recur = genA_recur(i); 
        std::cout << "recurrsion: n = " << i << " => " << res_recur << std::endl;
        calls.clear(); 

        std::cout << std::endl; 
    }
    return EXIT_SUCCESS; 
}
*/