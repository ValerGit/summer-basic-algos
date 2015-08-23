#include <iostream>

using namespace std;

struct findMeMax
{
    bool found = false;
    int index = 0;
};

struct Array
{
    Array() {}
    Array(const Array& obj)
    {
        number = obj.number;
        figure = obj.figure;
    }
    ~Array() {}
    int number = 0;
    int figure = 0;
};

class Heap
{
public:
    Heap(Array*, int);
    ~Heap() { delete[] arr; }
    void buildHeap();
    void siftUp(int);
    void siftDown(int);
    Array extractMax();
    void print();
    void swapper(int, int);
private:
    Array* arr;
    int size;
};

Heap::Heap(Array* array, int n)
{
    size = n;
    arr = new Array[size];
    for(int i = 0; i < size; ++i)
    {
        arr[i] = array[i];
    }
    buildHeap();
}

void Heap::buildHeap()
{
    for(int i = size/2 - 1; i >= 0; --i)
    {
        siftDown(i);
    }
}

void Heap::swapper(int first, int second)
{
    swap(arr[first].figure, arr[second].figure);
    swap(arr[first].number, arr[second].number);
}

void Heap::siftDown(int i)
{
    while(i <= (size/2 -1))
    {
        int biggest = 0, smallest = 0;
        if(arr[2*i+1].figure > arr[2*i+2].figure)
        {
            biggest = 2*i + 1;
            smallest = 2*i + 2;
        }
        else
        {
            biggest = 2*i + 2;
            smallest = 2*i + 1;
        }
        if(arr[i].figure < arr[biggest].figure)
        {
            swapper(i, biggest);
            i = biggest;
        }
        else if (arr[i].figure < arr[smallest].figure)
        {
            swapper(i, smallest);
            i = smallest;
        }
        else return;
    }
}

Array Heap::extractMax()
{
    Array temp;
    temp = arr[0];
    arr[0] = arr[--size];
    siftDown(0);
    return temp;
}

void Heap::siftUp(int i)
{
    while(i >= 0)
    {
        if(arr[i].figure > arr[(i-1)/2].figure)
        {
            swapper(i, ((i-1)/2));
            i = (i-1)/2;
        }
        else return;
    }
    return;
}

void Heap::print()
{
    cout <<"-----------------------------------------"<< endl;
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i].number <<" " << arr[i].figure <<endl;
    }
    cout <<"-----------------------------------------"<< endl;
}

int main()
{
    int n = 0;
    cin >> n;
    Array* arr = new Array[n];
    for(int i = 0; i < n; ++i)
    {
        arr[i].number = i;
        cin >> arr[i].figure;
    }
    int k = 0;
    cin >> k;
    Heap mine(arr, n);
    //mine.print();
    findMeMax* find = new findMeMax[n-k+1];
    int cntr = 0;
    while(cntr < n-k+1)
    {
        Array max = mine.extractMax();
        int maxIndex = max.number;
        int maxFigure = max.figure;
        int iterator = 0;
        if((maxIndex - k + 1) > 0)
        {
            iterator = (maxIndex - k + 1);
        }
        int maxBorder = n - k;
        if((maxIndex + k -1) < n - k)
        {
            maxBorder = maxIndex;
        }
        while(iterator <= maxBorder)
        {
            if(find[iterator].found == false)
            {
                find[iterator].found = true;
                find[iterator].index = maxFigure;
                ++cntr;
            }
            ++iterator;
        }
    }
    for(int i = 0; i < n-k+1; ++i)
    {
        cout << find[i].index << " ";
    }
    return 0;
}

