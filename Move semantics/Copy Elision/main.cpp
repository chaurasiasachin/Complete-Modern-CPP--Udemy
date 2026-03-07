#include "Integer.h"
#include <iostream>
#include <utility>

void Print(Integer val){

}
int main(){
    Integer a(1); // -> creating the object
    a.SetValue(3); // after creating we may be Initializing it here or perform any operations.
    // Now we dont want the state of a. But instead we want the state of a in some other
    // object, let say b. Son, that case we will apply std::move on it.
    //auto b{std::move(a)};

    // This is commonly required when we have function like void Print(Integer val)
   //Print(a);
   // Now we dont want the state of a after print funtion instead of leting compiler copy
   // this object into val, you can move it.
   // The advantage is that when we move the state of 'a' oobject into val after the print
   // function finishes, the val object will be destroyed. And will release the underlying
   // resources.
   // If we simply pass 'a' object by value in Print function, a copy is created. When
   // integer object val is destroyed here, it will release its own resources, but the
   // underlying resources of 'a' will be released only at end of the main function.
   // And we dont want to use the resources of 'a' after the print function. Thats why
   // we will implement move. Instead of Print(a); we will write Print(std::move(a));
   Print(std::move(a));

   // This is common pattern with unique pointer. Unique pointer is a Smart Pointer.
   // Thats why we heavily use std::move in Smart Pointers.
   // After we move from 'a', we cannot read from the object 'a'. This is because in move
   // constructor Integer::Integer(Integer &&obj) we are doing obj.m_pInt = nullptr;
   // that is we are assigning null pointer to the member. So if try to read from 'a',
   // the program may crash
   //std::cout<<a.GetValue()<<std::endl;

   //So, when we move from an object. The object is in unspecified state.
   // but the object is still a valid object and we can reinitialise it and reuse it.
   a.SetValue(5); // -> do this first (Also the implementation of SetValue must be corrected)
   std::cout<<a.GetValue()<<std::endl;
     
}