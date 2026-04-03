//
// Created by i on 03-04-2026.
//
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
vector<int>shared_data;

void producer() {
    for (int i=1;i<=100;i++) {
        shared_data.push_back(i); //not thread safe
        this_thread::sleep_for(chrono::milliseconds(1)); //producing slowly slowly
    }
}

void consumer() {
    for (int i=1;i<=100;i++) {
        cout<<"current size: "<<shared_data.size()<<endl; //not thread safe
        this_thread::sleep_for(chrono::microseconds(500));  //reading fast super fast wrong info loop in speed
    }
}
int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    cout<<"final size="<<shared_data.size()<<endl;
    return 0;

}
