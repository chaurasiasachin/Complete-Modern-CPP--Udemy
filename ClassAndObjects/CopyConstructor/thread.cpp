// Online C++ compiler to run C++ program online
#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex mtx;
condition_variable cv;
int turn = 1;
void print_even(int n){
    for(int i = 2;i<=n;i+=2){
       unique_lock<mutex> lock(mtx);
       cv.wait(lock,[]{return turn == 2;});
       cout<<i<<endl;
       turn = 1;
       cv.notify_all();
    }
}
void print_odd(int n){
    for(int i = 1;i<=n;i+=2){
        unique_lock<mutex> lock(mtx);
       cv.wait(lock,[]{return turn == 1;});
       cout<<i<<endl;
       turn = 2;
       cv.notify_all();
    }
}
int main() {
    int n;
    cin>>n;
    thread t1(print_even,n);
    thread t2(print_odd,n);

    t1.join();
    t2.join();

    return 0;
}