//多态的实现
#include <iostream>
using namespace std;

/*实现多态的实例代码*/

//基类
class Animal {
    public:
    virtual void makeSound() {
        cout << "this is Animal !" << endl;
    }
};

//cat子类
class Cat: public Animal {
    public:
    void makeSound() {
        cout << "this is Cat!" << endl;
    }
};

//Dog类
class Dog: public Animal {
    public:
    void makeSound() {
        cout << "this is Dog!" << endl;
    }
};

int main() {
    //创建基类指针
    Animal* a;
    Cat c;
    Dog d;
    //基类指针指向Cat对象
    a = &c;
    a->makeSound();
    //基类指针指向Dog对象
    a = &d;
    a->makeSound();
    return 0;
}