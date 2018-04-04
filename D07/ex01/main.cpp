#include "iter.hpp"

int main(){
    int arrInt [] = {
        1 , 2, 3
    };
    test<int, size_t>(arrInt, 3);
    
    char arrChar [] = {
        'a', 'b', 'c'
    };
    test(arrChar, 3);
    return 0;
}