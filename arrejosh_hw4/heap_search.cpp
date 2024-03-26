#include "heap_search.h"

template <typename T, typename Compare>
T MinHeap<T, Compare>::get_kth_smallest(int k) {
    if (k > size)
        throw std::out_of_range("The heap contains less than k elements");
	// ...
    // your code here
    // ...

    //keeps track for finding the kth smallest index
    MinHeap<T,Compare> temp(capacity,compare); 
    temp.insert(arr[0]); 

    T kthsmallest; 

    //find it by looping through k indicies 
    for(int i = 0; i < k; i++){
        //smallest in temp heap
        kthsmallest = temp.extract_min(); 

        //index of extracted value in original heap
        int index = std::distance(arr, std::find(arr, arr + size, kthsmallest)); 

        /*
            If both sides are valid itll enter the right and left child into the temp heap
        */

        int left = left_child(index); 
        if(left < size){
            temp.insert(arr[left]); 
        }

        int right = right_child(index); 
        if(right < size){
            temp.insert(arr[right]); 
        }

    }


    return kthsmallest; // don't forget to change this
}


//test cases
/*int main() {
    // Test case 1
    MinHeap<int> heap1(10);
    heap1.insert(100);
    heap1.insert(200);
    heap1.insert(300);
    heap1.insert(400);
    std::cout << "Test 1 - Expected: 200, Got: " << heap1.get_kth_smallest(2) << std::endl;

    // Test case 2
    MinHeap<int> heap2(10);
    heap2.insert(-1);
    heap2.insert(-2);
    heap2.insert(-3);
    std::cout << "Test 2 - Expected: -3, Got: " << heap2.get_kth_smallest(1) << std::endl;

    // Test case 3
    MinHeap<int> heap3(10);
    heap3.insert(22);
    heap3.insert(21);
    heap3.insert(23);
    heap3.insert(20);
    heap3.insert(24);
    std::cout << "Test 3 - Expected: 24, Got: " << heap3.get_kth_smallest(5) << std::endl;

    // Test case 4
    MinHeap<int> heap4(10);
    heap4.insert(40);
    heap4.insert(10);
    heap4.insert(30);
    heap4.insert(20);
    std::cout << "Test 4 - Expected: 30, Got: " << heap4.get_kth_smallest(3) << std::endl;

    // Test case 5
    MinHeap<int> heap5(10);
    heap5.insert(9);
    heap5.insert(8);
    std::cout << "Test 5 - Expected: 9, Got: " << heap5.get_kth_smallest(2) << std::endl;

    // Test case 6
    MinHeap<int> heap6(10);
    heap6.insert(11);
    heap6.insert(111);
    heap6.insert(1111);
    heap6.insert(11111);
    std::cout << "Test 6 - Expected: 11111, Got: " << heap6.get_kth_smallest(4) << std::endl;

    return 0;
}
*/

