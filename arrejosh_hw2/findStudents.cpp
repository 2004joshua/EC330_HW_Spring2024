#include <vector> 
#include <algorithm> 

/*
    *This function must run faster than O(n^2)
    *considering the number part of BU ID so Uxxxxxxxx, 8 numbers
*/


std::vector<int> findStudents(std::vector<int> id){

    std::vector<std::pair<int, int>> newid; //O(1)

    int counter = 0; //O(1)
    for(auto &index : id){ //O(n)
        newid.push_back({index % 330,counter}); 
        counter++; 
    }
    //loop through id vector and get size through counter

    //O(n log(n)) for sort
    std::sort(newid.begin(), newid.end()); 

    int first = 0; //O(1)
    int second = counter - 1; //O(1)
    int msum = 329; //max that the %330 can be, O(1)
    std::pair<int, int> mpair; //pair the two ids, O(1) 

    while(first < second){ //O(n) 
        int sum = (newid[first].first + newid[second].first) % 330; 
        
        if(sum < msum){
            msum = sum; 
            mpair = {newid[first].second, newid[second].second}; 
        }

        if(sum > 165){
            --second; 
        }
        else{
            ++first; 
        }
    }

    //O(n log(n)) = O(n log(n)) + O(n) + O(n), overall its O(n log(n)) slower than O(n^2)
    return {mpair.first, mpair.second}; 
}