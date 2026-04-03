
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
    for (int i=0;i<10;i++) {
        thread t=thread(print,i);
        workers.push_back(move(t));
    }
    std::for_each(workers.begin(),workers.end(),[](thread &t) {
        assert(t.joinable());
        t.join();
    });
    return 0;
}