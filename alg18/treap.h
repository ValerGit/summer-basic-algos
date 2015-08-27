#ifndef TREAP
#define TREAP
#include <iostream>
using namespace std;

struct Node {
    Node() {}
    ~Node() {}
    Node(int x, int y) : key(x), priority(y){}
    int key = 0;
    int priority = 0;
    int subHeight = 0;
    Node* left = 0;
    Node* right = 0;
};

class Treap{
public:
    Treap() {}
    ~Treap() {
        deleting(head);
        delete head;
    }
    void addElement(int key, int priority);
    void printing(){
        print(head);
    }
    int getHeight(){
        return calcHeight(head);
    }
private:
    Node* head = 0;
    int height = 0;
    void merzh(Node*& T,Node* L, Node* R);
    void split(Node* T, int key, Node *&L, Node *&R);
    int calcHeight(Node*);
    void print(Node*);
    void deleting(Node*);
};

#endif // TREAP

