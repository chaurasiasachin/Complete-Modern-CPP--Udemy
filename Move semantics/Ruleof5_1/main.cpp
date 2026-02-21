#include "Integer.h"
class Number{
    Integer m_value{};
public:
    Number(int value):m_value(value){

    }
};

int main(){
    Number n1{1};
    auto n2{n1};
    n2 = n1;
}

// Copy assignment operator
// Since Integer is a member of Number class, when we use the instances of Number
// in an expression that requires copying or moving, the compiler will automatically sunthesis
// the corresponding copy and move operation for the Number class.
// And Since we are logging the calls to the function in the Integer class. This way
// we will be able to know what functions are synthesise for the number class 
// because any function that is synthesise in the Number class will internally call
// the corresponding function of the Integer class.
// It is not possible otherwise to see whether the compiler has synthesise the copy
// and move operation