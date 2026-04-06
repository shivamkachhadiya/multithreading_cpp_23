
//
// Created by i on 03-04-2026.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <mutex>
#include<vector>
#include<thread>
using namespace std;
mutex m;

void print(int i) {
    //lock_guard<mutex>lock(m);
    cout<<"i am worker thread no : "<<i<<endl;
    cout<<"check for multi thread"<<endl;
}
int main() {
    vector<thread>workers;
    for (int i=0;i<10;i++) {
        thread t=thread(print,i);
        workers.push_back(move(t));
    }
    for (thread &t : workers) {
        if (t.joinable()) {
            t.join();
        }
    }
    return 0;
}