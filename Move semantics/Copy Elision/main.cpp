#include "Integer.h"
#include <iostream>

Integer Add (int a, int b){
   Integer temp(a+b); // 1 object is created
   return temp; // this object is return by value. So, another object is created.
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