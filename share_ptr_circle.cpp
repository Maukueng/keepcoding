//智能指针的环形引用问题，以及使用解决方案
#include <iostream>
using namespace std;
#include <memory>

class Node {
    public:
    Node() {
        cout << "node constructor!" << endl;
    }
    //使用共享指针，会造成环形引用
    shared_ptr<Node> next;
    //使用weak_ptr解决环形引用问题
    //weak_ptr<Node> next;

    ~Node() {
        cout << "node destructor!" << endl;
    }

};

int main() {
    shared_ptr<Node> node1 = make_shared<Node>();
    shared_ptr<Node> node2 = make_shared<Node>();
    //若要使用new创建，先创建裸指针，再拷贝到智能指针，但是不建议，因为可能会造成内存泄漏
    /* Node* n = new Node();
    shared_ptr<Node> node1(n); */
    //互相指向
    node1->next = node2;
    node2->next = node1;
    //查看引用计数器
    cout << "node1:" << node1.use_count() << endl;
    cout << "node2:" << node1.use_count() << endl;
    //程序没有执行析构函数，内存泄漏
    return 0;
}