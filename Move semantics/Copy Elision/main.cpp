#include "Integer.h"
#include <iostream>

Integer Add (int a, int b){
    /*
    NVRO
   Integer temp(a+b); // 1 object is created
   return temp; // this object is return by value. So, another object is created.
                // NRVO
                 // Here the compiler has not created a copy of temp object            
                //becaise its elided. This is another form of copy elision and is
                    // Named return value optimization (NRVO)
   */
    return Integer(a+b); // this is better creating temp object in return itself.
                    //even here compiler will elide the copy that needs to be created 
                    // when we return object from here. This is called as
                    // (RVO) Return value optimization 

}
int main(){
    //Integer a = 3; // Integer a = Integer(3);
    Integer a = Add(3,5); // the object created at line 6 is copied and moved into a.
    return 0;
}
// NRVO (Named return value optimisation)
/*
g++ -std=c++17 main.cpp Integer.cpp -o main && ./main
Integer(int )
~Integer()

g++ -std=c++17 -fno-elide-constructors main.cpp Integer.cpp -o main && ./main
Integer(int )
Integer(Integer &&)
~Integer()
~Integer()

g++ -std=c++17 main.cpp Integer.cpp -o main && ./main
Integer(int )
~Integer()

g++ -std=c++14 main.cpp Integer.cpp -o main && ./main
Integer(int )
~Integer()
*/