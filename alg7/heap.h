#ifndef HEAP
#define HEAP
using namespace std;

const int startSize = 1;
const int growFactor = 2;

class Heap
{
public:
    Heap(int*, int);
    ~Heap();
    void siftDown(int);
    void siftUp(int);
    void buildHeap();
    void insert(int);
    int extractMax();
    void deleteElement(int);
    int showElement(int i) { return arr[i]; }
    void print();
private:
    int* arr;
    int size;
    int buffSize;
    void grow();
};


Heap::~Heap()
{
    delete[] arr;
}

Heap::Heap(int* array, int n)
{
    arr = new int[n];
    size = buffSize = n;
    for(int k = 0; k < n; ++k)
    {
        arr[k] = array[k];
    }
    buildHeap();
}

void Heap::buildHeap()
{
    for(int k = size/2; 0 <= k; --k)
    {
        siftDown(k);
    }
}

void Heap::siftDown(int i)
{
    while((i < size) && (2*i+2 <= size ))
    {
        int biggest, smallest;
        if(arr[2*i+1] < arr[2*i+2])
        {
            biggest = 2*i + 2;
            smallest = 2*i + 1;
        }
        else
        {
            biggest = 2*i + 1;
            smallest = 2*i + 2;
        }
        if(arr[i] < arr[biggest])
        {
            swap(arr[i], arr[biggest]);
            i = biggest;
        }
        else if(arr[i] < arr[smallest])
        {
            swap(arr[i], arr[smallest]);
            i = smallest;
        }
        else return;
    }
}

void Heap::siftUp(int i)
{
    while(i >= 0)
    {
        if(arr[i] > arr[(i-1)/2])
        {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
        else return;
    }
}

int Heap::extractMax()
{
    int temp = arr[0];
    arr[0] = arr[size-1];
    siftDown(0);
    --size;
    return temp;
}

void Heap::insert(int i)
{
    if(size == buffSize) grow();
    arr[size] = i;
    siftUp(size++);
}

void Heap::deleteElement(int i)
{
    arr[i] = arr[--size];
    siftDown(i);
}

void Heap::print()
{
    for(int k = 0; k < size; ++k)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
}

void Heap::grow()
{
    buffSize *= growFactor;
    int* temp = new int[buffSize];
    for(int i = 0; i < size; ++i)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

#endif // HEAP

