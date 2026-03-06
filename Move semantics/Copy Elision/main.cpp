#include "Integer.h"
#include <iostream>
#include <utility>

int main(){
   Integer a(1);
   // auto b{a}; // Creating copy of object a in b. because a is L-value, the function overload
          // resolution will choose function Integer(const Integer &obj); because parameter
          // here is of type L-value.
          // In some cases we may not want to create the copy of this object. Instead we
          // may want to move it into b. But by default because of function overload 
          // resolution, the compiler will always choose the copy constructor.
          // To Force the compiler to use the move constructor, we can apply a
          // type cast on the object a and the type cast can be a static cast to an R-value
          // reference 

    //auto b{static_cast<Integer &&>(a)};
    auto b{std::move(a)};
     
}