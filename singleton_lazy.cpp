//单例设计模式之懒汉模式
#include <iostream>
using namespace std;
#include <mutex>

//懒汉模式不是线程安全的，必须加锁
std::mutex mtx;
class Singleton {
    private:
    static Singleton* instance;
    Singleton() {} //构造函数必须私有，防止外部实例化
    public:
    static Singleton* getInstance() { //返回唯一实例
        if (instance == nullptr) {
            mtx.lock();
            if (instance == nullptr) {
                instance  = new Singleton();
            }
            mtx.unlock();
        }
        return instance;
    }
    void show() {
        cout << "hello single lazy!" << endl;
    }
};

Singleton *Singleton::instance = nullptr; //类外初始化静态成员变量

int main() {
    //通过getIntance()方法获取唯一实例
    Singleton *single = Singleton::getInstance();
    single->show();
    return 0;
}