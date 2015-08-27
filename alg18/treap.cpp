#include <treap.h>

void Treap::split(Node *T, int key, Node*& L, Node*& R){
    if(T == 0){
        L = R = 0;
        return;
    }
    if(T->key < key) {
        split(T->right, key, T->right, R);
        L = T;
    } else {
        split(T->left, key, L, T->left);
        R = T;
    }
}

void Treap::merzh(Node*& T, Node *L, Node *R){
    if(L == 0 || R == 0){
        if(L != 0) T = L;
        else T = R;
        return;
    }
    if(L->priority > R->priority)
    {
        merzh(L->right, L->right, R);
        T = L;
    } else {
        merzh(R->left, L, R->left);
        T = R;
    }
}

void Treap::addElement(int key, int priority){
    if(head == 0){
        head = new Node(key, priority);
        return;
    }
    Node* L = new Node, *R = new Node, *res = new Node;
    split(head, key, L, R);
    Node* temp = new Node(key, priority);
    merzh(res, L, temp);
    merzh(head, res, R);
}

void Treap::print(Node* root){
    if(root == 0) return;
    print(root->left);
    cout << root->key <<" " << root->priority << endl;
    print(root->right);
}

int Treap::calcHeight(Node* root){
    if(root == 0) return 0;
     return 1 + max(calcHeight(root->left), calcHeight(root->right));
}

void Treap::deleting(Node* root){
    if(root == 0) return;
    deleting(root->left);
    deleting(root->right);
    delete root->left;
    delete root->right;
}
