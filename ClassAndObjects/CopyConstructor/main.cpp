#include "Integer.h"
#include <iostream>
/* Another two scenarios wher copy of the object is created
void Print(Integer i){
		// second case when copy constructor is created
}

Integer Add(int x, int y){  // Third case  
		return Integer(x+y); 
} 
*/
int main(){
    // int * p1 = new int(5);
    // // Shallow copy
    // int *p2 = p1;

    // // Deep copy
    // int *p3 = new int(*p1);

    Integer i(5);
    Integer i2(i);
    std::cout<<i.GetValue()<<std::endl;
}