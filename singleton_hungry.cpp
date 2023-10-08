//单例设计模式-饿汉
#include <iostream>
using namespace std;

class Singleton {
    private:
    Singleton() {} //单例模式的构造函数必须私有化，防止被外部实例化
    static Singleton* instance;
    public:
    static Singleton* getInstance() {
        return instance;
    }
    void show() {
        cout << "hello hungry!" << endl;
    }
};

//静态成员变量必须在类外初始化，且只在程序开始的时候初始化一次
Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* single = Singleton::getInstance();
    single->show();
    return 0;
}

