//
// Created by i on 03-04-2026.
//
#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;

void Demoan() {
    while (1) {
        cout<<"i am demoan thread, No one can kill me except process is terminated..."<<endl;
        this_thread::sleep_for(1000ms);
    }
}
int main() {
    thread t1(Demoan);

    t1.detach();

    this_thread::sleep_for(5000ms);

    return 0;
}