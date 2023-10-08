//抽象工厂设计模式
#include <iostream>
using namespace std;

class Product {
    public:
    Product() {}
    virtual void show() = 0;
    ~Product() {}
};

class ProductA: public Product {
    public:
    ProductA() {}
    void show() {
        cout << "make productA!" << endl;
    }
    ~ProductA() {}
};

class ProductB: public Product {
    public:
    ProductB() {}
    void show() {
        cout << "make productB!" << endl;
    }
    ~ProductB() {}
};

class Factory {
    public:
    //Factory() {}
    virtual Product* make() = 0;
    //~Factory() {}
};

class FactoryA: public Factory {
    public:
    FactoryA() {}
    Product* make() {
        return new ProductA();
    }
    ~FactoryA() {}
};

class FactoryB: public Factory {
    public:
    FactoryB() {}
    Product* make() {
        return new ProductB();
    }
    ~FactoryB() {}
};

int main() {
    Factory* fA = new FactoryA();
    Product* pA = fA->make();
    pA->show();

    Factory* fB = new FactoryB();
    Product* pB = fB->make();
    pB->show();

    return 0;
}