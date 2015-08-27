#include <iostream>
#include <treap.h>
#include <bstree.h>
using namespace std;

int main()
{
    int arrX[10] = { 5, 18, 25, 50, 30, 15, 20, 22, 40, 45};
    int arrY[10] = { 11, 8, 7, 12, 30, 15, 10, 5, 20 ,9};
    Treap one;
    BSTree two;
    for(int i = 0; i < 10; ++i)
    {
        one.addElement(arrX[i], arrY[i]);
        two.adding(arrX[i]);
    }
    cout << one.getHeight() << endl;
    cout << two.getHeight() << endl;
    return 0;
}

