//死锁的实现
#include <iostream>
using namespace std;
#include <thread>
#include <mutex>

std::mutex mtx1;
std::mutex mtx2;

void func1() {
    cout << "func1" << endl;
    mtx1.lock();
    cout << "func1 mtx1 lock" << endl;
    mtx2.lock();
    cout << "funx1 mtx2 lock" << endl;

    mtx2.unlock();
    mtx1.unlock();
}

void func2() {
    cout << "func2" << endl;
    mtx2.lock();
    cout << "func2 mtx2 lock" << endl;
    mtx1.lock();
    cout << "func2 mtx1 lock" << endl;

    mtx1.unlock();
    mtx2.unlock();
}

int main() {
    thread t1(func1);
    thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}