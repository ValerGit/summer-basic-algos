#include <iostream>

using namespace std;

int binSearch(int arr[],int size, int num)
{
    int j = 0;
    for(j = 1; j < size; j *= 2)
    {
        if(arr[j] > num) break;
    }
    int l = j / 2;
    int r = size-1;
    while(l < r)
    {
        int m = (r + l) / 2;
        if(arr[m] < num) l = m + 1;
        else r = m;
    }
    return r;
}

int main()
{
    int n = 0, k = 0;
    cout << "Enter A array size\t";
    cin >> n;
    int arrA[n];
    cout << "Enter A array\t";
    while(k < n)
    {
        cin >> arrA[k++];
    }
    int _n = 0, _k = 0;
    cout << "Enter B array size\t";
    cin >> _n;
    int arrB[_n];
    out << "Enter B array\t";
    while(_k < _n)
    {
        cin >> arrB[_k++];
    }
    int resArr[_k];
    for(int i = 0; i < _k; ++i)
    {
        resArr[i] = binSearch(arrA, n, arrB[i]);
        cout << resArr[i] <<" ";
    }
    cout << endl;
    return 0;
}

