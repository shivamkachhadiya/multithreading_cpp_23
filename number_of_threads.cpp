
//
// Created by i on 03-04-2026.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include<vector>
#include<thread>
using namespace std;
void print(int i) {
    cout<<"i am worker thread no : "<<i<<endl;
}

int main() {
    vector<thread>workers;
    unsigned long const hardware_threads=thread::hardware_concurrency();
    cout<<hardware_threads<<endl;

    for (int i=0; i<hardware_threads;i++) {
        workers.emplace_back(thread(print   ,i));
    }

    for (auto &t : workers) {
        if (t.joinable()) {
//            cout<<"thread id is--->"<<t.get_id()<<endl;
            t.join();
        }
    }
    return 0;
}