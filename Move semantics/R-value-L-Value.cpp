#include <iostream>
using namespace std;
// Returns r-value
int add (int x, int y){
    return x + y;
}

// Returns l-value
int &transform(int &x){
    x *= x;
    return x;
}

void Print(int &x){
    std::cout<<"Print(int &x)" <<std::endl;
}

void Print(const int &x){
    std::cout<<"Print(const int &x)" <<std::endl;
}

void Print(int &&x){
    std::cout<<"Print(int &&x)" <<std::endl;
}

int main(){

    int x = 10;
    Print(x);
    Print(3);
    return 0;

}