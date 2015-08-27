#ifndef BST
#define BST
#include <iostream>
using namespace std;

struct NodeBST{
    NodeBST() {}
    NodeBST(int val) : value(val){}
    NodeBST(const NodeBST& obj) : value(obj.value) {
        left = new NodeBST;
        left = obj.left;
        right = new NodeBST;
        right = obj.right;
    }
    ~NodeBST() {}
    int value;
    NodeBST* left = 0;
    NodeBST* right = 0;
    int subNodes = 0;
    int height = 0;
};

class BSTree {
public:
    BSTree() {}
    ~BSTree(){
        deleting(head);
        delete head;
    }
    void adding(int x){
        addElement(head, x);
    }
    int getHeight(){
        calcHeight(head);
        return height;
    }
private:
    void deleting(NodeBST*);
    NodeBST* addElement(NodeBST* , int );
    void calcHeight(NodeBST* );
    NodeBST* head = 0;
    int height = 0;
};

#endif // BST

