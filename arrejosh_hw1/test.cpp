#include "fun.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <cassert>

int main(){

    assert(fun(0,0) == 1); 
    assert(fun(0,1) == 2); 
    assert(fun(1,1) == 2); 
    
    return EXIT_SUCCESS; 
}