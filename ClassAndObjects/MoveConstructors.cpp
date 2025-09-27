#include <iostream>
#include <algorithm>
#include <vector>
class Myarray{
    int size;
    int *data;

public:
    Myarray(int n):size(n),data(new int[n]){
        std::cout<<"Constructed"<<std::endl;
    }
    ~Myarray(){delete[] data;}

    // Copy Constructor
        // normal way
        // Myarray(const Myarray &obj){
        //     size = obj.size;
        //     data = new int[obj.size];
        // }
    // Copy Constructor
    Myarray(const Myarray &obj):size(obj.size),data(new int[obj.size]){
        std::copy(obj.data,obj.data+size,data);
        std::cout<<"Copy Constructor"<<std::endl;
    }

    // Move Constructor
    Myarray(Myarray&& obj) noexcept : size(obj.size), data(obj.data){
        obj.size = 0;
        obj.data = nullptr; // important: release ownership
        std::cout<<"Move constructor"<<std::endl;
    }
};
int main(){
    Myarray a(10000000);
    Myarray b = a; // copy constructor -> DEEP copy of 1 million ints!
    Myarray c = Myarray(10000); // r-value -> move constructor
                    // This itslef will not invoke Move constructor. Because
                            // after C++17 it will behave copy elision.
    Myarray d = std::move(c); // force treating a as rvalue → move constructor
    
    // Another way is to use STL
    std::vector<Myarray> v;
    v.push_back(Myarray(5));  // temporary object --> Only move constructor will be
                            // called in this case.
                            // Comment move constructor it will call copy constructor
}