#include <iostream>
using namespace std;
#include <mutex>
#include <thread>

std::mutex mtx;

class lazySingle {
    private:
        static lazySingle* instance;
        lazySingle() {}
    public:
    static  lazySingle* getInstance() {
            if (instance == nullptr) {
                mtx.lock();
                if (instance  == nullptr) {
                    instance = new lazySingle();
                }
                mtx.unlock();
            }
            return instance;
        }

};

lazySingle* lazySingle::instance = nullptr;

int main() {
    lazySingle* p = lazySingle::getInstance();
}