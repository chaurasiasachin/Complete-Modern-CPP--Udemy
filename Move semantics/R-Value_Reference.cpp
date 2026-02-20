#include <iostream>
using namespace std;
// Returns r-value
int add (int x, int y){
    return x + y;
}

// Returns l-value
int &transform(int &x){
    x *= x;
    return x;
}


int main(){

    int &&r1 = 10;
    int &&r2 = add(3,2);

    // R-value reference cannot bind to a l-value
    int x = 0;
    //int &&r3 = x;

    int &ref = x; // This is fine
    int &ref1 = transform(x); //this is also fine because transform returns by reference.

    const int &ref2 = 10; // binding to temporaries only if it is constant (const).

    return 0;

}