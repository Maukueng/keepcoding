//简单工厂设计模式
#include <iostream>
using namespace std;

class Product {
    public:
    Product() {}
    virtual void show() = 0;
    virtual ~Product() {}
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
    Factory() {};
    Product* make(const string& s) {
        if (s == "A") {
            return new ProductA;
        }
        if (s == "B") {
            return new ProductB;
        }
        return nullptr;
    }
    ~Factory() {}
};

int main() {
    Factory f;
    Product* A = f.make("A");
    Product* B = f.make("B");
    A->show();
    B->show();
    return 0;
}