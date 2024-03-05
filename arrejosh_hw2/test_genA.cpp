#include <chrono> 
#include <iostream> 
#include "genA.h"
#include <map>
#include <utility> 
#include <fstream> 

void runtime(){

    std::map<int, std::pair<long long, long long> > time_info;    // <n, <time f, time g>> f is iter g is recurr

    for(int i = 0; i < 1000; i++){ //we getting the data 
        
        auto start1 = std::chrono::high_resolution_clock::now(); 
        genA_recur(i); 
        auto stop1 = std::chrono::high_resolution_clock::now(); 
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop1 - start1); 
        auto start2 = std::chrono::high_resolution_clock::now(); 
        genA_iter(i); 
        auto stop2 = std::chrono::high_resolution_clock::now(); 
        auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop2 - start2); 

        time_info[i] = std::make_pair(duration1.count(), duration2.count());

    }

    std::ofstream out_file("runtime.csv"); 
    out_file << "n, genA_recur, genA_iter\n";

    for(const auto& [n,times] : time_info){
        out_file << n << ", " << times.first << ", " << times.second << "\n"; 
    } 
    out_file.close(); 
    
}; 

int main(){

    //give me the csv

    runtime(); 

    return EXIT_SUCCESS; 
}