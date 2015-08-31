#include <iostream>

using namespace std;
const int growFac = 2;

struct Node
{
    Node() {}
    ~Node() {}
    Node(int k) : key(k), height(1), left(0), right(0) {}
    Node(const Node* obj) : key(obj->key), height(obj->height),
        left(obj->left), right(obj->right) {}
    int key;
    int height;
    Node* left;
    Node* right;
};

int getHeight(Node* root)
{
    if(!root) return 0;
    return root->height;
}

int bfactor(Node* root)
{
    if(!root) return 0;
    return (getHeight(root->right) - getHeight(root->left));
}

void fixHeight(Node* root)
{
    int hLeft = getHeight(root->left);
    int hRight = getHeight(root->right) ;
    root->height = 1 + (hLeft > hRight ? hLeft : hRight);
}


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


class AVL
{
public:
    AVL() { head = 0; }
    ~AVL() {}
    void adding(int x){
        head  = add(head, x);
    }
    void deliting(int x){
        head = del(head, x);
    }
    void printing() {
        cout << endl;
        cout << "--------------------" << endl;
        print(head);
        cout << endl;
        cout << "--------------------" << endl;
    }
    int getHeight(){
        return height(head);
    }

private:
    Node* add(Node* root, int x);
    Node* del(Node*root, int x);
    Node* rotateRight(Node* root);
    Node* rotateLeft(Node* root);
    Node* balance(Node* root);
    Node* findMin(Node* root);
    Node* removeMin(Node* root);
    Node* head;
    void print(Node*);
    int height(Node* root);
};

Node* AVL::rotateRight(Node* root)
{
    Node* q = root->left;
    root->left = q->right;
    q->right = root;
    fixHeight(root);
    fixHeight(q);
    return q;
}

Node* AVL::rotateLeft(Node* root)
{
    Node* p = root->right;
    root->right = p->left;
    p->left = root;
    fixHeight(root);
    fixHeight(p);
    return p;
}

Node* AVL::balance(Node* root)
{
    fixHeight(root);
    if(bfactor(root) == 2)
    {
        if(bfactor(root->right) < 0) root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    else if(bfactor(root) == -2)
    {
        if(bfactor(root->left) > 0) root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    else return root;
}

Node* AVL::add(Node* root,int x)
{
    if(root == 0) return new Node(x);
    if(x < root->key) root->left = add(root->left, x);
    else root->right = add(root->right, x);
    return balance(root);
}

Node* AVL::del(Node* root, int x)
{
    if(root == 0) return 0;
    if(x < root->key) root->left = del(root->left, x);
    else if(x > root->key) root->right = del(root->right, x);
    else
    {
        Node* l = root->left;
        Node* r = root->right;
        delete root;
        if(!r) return l;
        Node* temp = findMin(r);
        temp->right = removeMin(r);
        temp->left = l;
        return balance(temp);
    }
    return balance(root);

}

Node* AVL::findMin(Node* root)
{
    if(root->left == 0) return root;
    return findMin(root->left);
}

Node* AVL::removeMin(Node* root)
{
    if(root->left == 0) return root->right;
    root->left = removeMin(root->left);
    return balance(root);
}

void AVL::print(Node* root)
{
    if(root == 0) return;
    print(root->left);
    cout << root->key << " ";
    print(root->right);
}

int AVL::height(Node* root)
{
    if(root == 0) return 0;
    return 1 + max(height(root->left), height(root->right));
}


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


void grow(int*& arr, int size)
{
    int* temp = new int[size*growFac];
    for(int i = 0; i < size; ++i){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

int main()
{
    int size = 2, cntr = 0;
    int* arr = new int[size];
    while(!cin.eof()){
        if(cntr >= size)
        {
            grow(arr, size);
            size *= growFac;
        }
        cin >> arr[cntr++];
    }
    --cntr;
    AVL tree;
    for(int i = 0; i < cntr; ++i)
    {
        if(arr[i] < 0) tree.deliting(abs(arr[i]));
        else tree.adding(arr[i]);
    }
    delete[] arr;
    tree.printing();
    cout << tree.getHeight() <<endl;
    return 0;
}

