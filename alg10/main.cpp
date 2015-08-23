#include <iostream>

using namespace std;
const int growFactor = 2;
static int buffSize = 1;

void grow(int*& arr, int size)
{
    buffSize = size * growFactor;
    int* temp = new int[buffSize];
    for(int i = 0; i < size; ++i)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

void sort(int*& arr, int size)
{
    for(int  i = 0; i < size; ++i)
    {
        int min = arr[i];
        int min_i = i;
        for(int k = i; k < size; ++k)
        {
            if(arr[k] < min)
            {
                min  = arr[k];
                min_i = k;
            }
        }
        swap(arr[i], arr[min_i]);
    }
}

int main()
{
    int* arr = new int[buffSize];
    int size = 0;
    while(!cin.eof())
    {
        if(size == buffSize)
        {
            grow(arr, size);
        }
        cin >> arr[size++];
    }
    cout << endl;
    sort(arr, size);
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

