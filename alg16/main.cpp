#include <iostream>

using namespace std;

struct Node
{
    Node() {}
    Node(int val)
    {
        value = val;
    }
    Node(const Node& obj)
    {
        value = obj.value;
        left = new Node;
        left = obj.left;
        right = new Node;
        right = obj.right;
    }
    ~Node() {}
    int value;
    Node* left = 0;
    Node* right = 0;
    int subNodes = 0;
};

class BST
{
public:
    BST();
    ~BST();
    Node* addElement(Node* , int );
    void inSeq(Node*);
    void preSeq(Node*);
    void postSeq(Node*);
    void levSeq(Node*, int);
    void height(Node*, int curr);
    int element(Node*,int curr, int toFind);
    Node* head;
//private:
    void deleting(Node*);
    int hight;
};

BST::BST()
{
    head = 0;
    hight = 0;
}

BST::~BST()
{
    deleting(head);
    delete head;
}

void BST::deleting(Node* root)
{
    if(root == 0) return;
    deleting(root->left);
    deleting(root->right);
    delete root->left;
    delete root->right;
}

Node* BST::addElement(Node* root, int toAdd)
{
    if(head == 0)
    {
        head = new Node(toAdd);
        return 0;
    }
    if(root == 0) return new Node(toAdd);
    if(root->value <= toAdd) root->right = addElement(root->right, toAdd);
    else root->left = addElement (root->left, toAdd);
    return root;
}

void BST::inSeq(Node* root)
{
    if(root == 0) return;
    inSeq(root->left);
    cout << root->value << " ";
    inSeq(root->right);
}

void BST::preSeq(Node* root)
{
    if(root == 0) return;
    cout << root->value << " ";
    preSeq(root->left);
    preSeq(root->right);
}

void BST::postSeq(Node* root)
{
    if(root == 0) return;
    postSeq(root->left);
    postSeq(root->right);
    cout << root->value << " ";
}

void BST::levSeq(Node* root, int num)
{
    for(int i = 0; i < num; ++i)
    {
        cout << root[i].value << " ";
    }
    int iter = 0;
    Node* arr = new Node[num*2];
    for(int i = 0; i < num; ++i)
    {
        if(root[i].left != 0  && root[i].right != 0)
        {
            arr[iter++] = *root[i].left;
            arr[iter++] = *root[i].right;
        }
        else if(root[i].left == 0 && root[i].right != 0)
        {
            arr[iter++] = *root[i].right;
        }
        else if(root[i].right == 0 && root[i].left != 0)
        {
            arr[iter++] = *root[i].left;
        }
    }
    if(iter == 0) return;
    levSeq(arr, iter);
    delete[] arr;
}

void BST::height(Node* root, int curr)
{
    if(root == 0) return;
    hight = ++curr;
    height(root->left, curr);
    hight = ++curr;
    height(root->right, curr);
    if(curr > hight) hight = curr;
}

int BST::element(Node* root, int curr, int toFind)
{
    if(root == 0) return 0;
    if(toFind == curr) return root->value;
    element(root->left, curr, toFind);
    hight = ++curr;
    element(root->right, curr, toFind);
    if(curr > hight) hight = curr;
}

int main()
{
    int arr[9] = {4, 7, 14, 6, 1, 3, 13, 10, 8};
    BST mine;
    for(int i = 0; i < 9; ++i)
    {
        mine.addElement(mine.head, arr[i]);
    }
    mine.levSeq(mine.head, 1);
//    cout << endl;
//    mine.height(mine.head,0);
//    cout << mine.hight << endl;
    return 0;
}

