#include "Integer.h"
#include <iostream>

// Writing a function that calculates the sum of two Integer objects 
// and function will return result by value
Integer Add (const Integer &a ,const Integer &b){
   // Creating a temporary object to hold the result of addition
   Integer temp;
   temp.SetValue(a.GetValue() + b.GetValue());
   return temp; // returning the temporary object by value
}
int main(){
    Integer a(1), b(3);
    a.SetValue(Add(a,b).GetValue());
    return 0;
}