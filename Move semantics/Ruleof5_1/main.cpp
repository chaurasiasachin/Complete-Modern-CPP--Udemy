#include "Integer.h"
class Number{
    Integer m_value{};
public:
    Number(int value):m_value(value){

    }
    // Number(const Number &n):m_value(n.m_value){
    // }
    ~Number(){};
};

Number CreateNumber(int num){
    Number n{num};
    return n;
}

int main(){
    Number n1{1};  
    auto n2{n1};
    n2 = n1;
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


    auto n3{CreateNumber(3)};
    n3 = CreateNumber(3);
    // Move assignment operator
    // In this case createNumber will return an r-value. So, compiler will choose
    // move constructor for the number. But the Number class does not contain a move 
    // constructor. However Integer class contains a move constructor.
    // So compiler will automatically synthesis the move constructor for the
    // Number class that will internally invoke the move contructor of Integer class
    // Same thing will apply to move assignment operator
}