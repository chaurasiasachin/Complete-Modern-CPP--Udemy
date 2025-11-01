#include <iostream>
using namespace std;
// Returns r-value
int add (int x, int y){
    return x + y; // Returned value is temporary
                // THis function cannot come on the left side of assignment operator.
}

// Returns l-value
int &transform(int &x){
    x *= x;
    return x;  // this fucntion can be written to the left side
                // and can be assigned with some value.
}

int main(){

    // x,y and z are l-values & 5,10 and 8 are r-values because they are variables and
    // they have a name
    int x = 5;
    int y = 10;
    int z = 8;

    // Expression returns r-value
    int res = (x + y) * z;

    // Expression returns l-value
    ++x = 6;

    return 0;

}