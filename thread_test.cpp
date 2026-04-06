#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
const int SIZE = 1000;
std::vector<int> it;
std::mutex it_mutex;

void download1() {
    for (int i = 0; i < SIZE; i++) {
        std::lock_guard<std::mutex> lock(it_mutex);
        it.push_back(i);
    }
}

void download2() {
    for (int i = 0; i < SIZE; i++) {
        std::lock_guard<std::mutex> lock(it_mutex);
        it.push_back(i);
    }
}

int main() {
    std::thread th1(download1);
    std::thread th2(download2);

    th1.join();
    th2.join();

    std::cout << "final size is " << it.size() << std::endl;
}