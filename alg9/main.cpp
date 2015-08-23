#include <iostream>
using namespace std;

struct Box
{
    Box() {}
    Box(const Box& obj)
    {
        size = obj.size;
        number = obj.number;
    }
    ~Box() {}
    int size = 0;
    int number = 0;
};

class Heap
{
public:
    Heap(Box*, int);
    ~Heap() { delete[] boxes; }
    void siftDown(int);
    void heapify();
    void print();
    void printNumbers();
    void swapper(int, int);
    Box extractMax();
    void sort();
private:
    int num;
    Box* boxes;
};

Heap::Heap(Box* boxs, int number)
{
    num = number;
    boxes = new Box[num];
    for(int i = 0; i < num; ++i)
    {
        boxes[i] = boxs[i];
    }
    heapify();
}

void Heap::swapper(int first, int second)
{
    swap(boxes[first].number, boxes[second].number);
    swap(boxes[first].size, boxes[second].size);
}

void Heap::siftDown(int i)
{
    while(i <= (num/2 - 1))
    {
        int biggest = 0, smallest = 0;
        if(boxes[2*i + 1].size < boxes[2*i + 2].size)
        {
            smallest = 2*i + 1;
            biggest = 2*i + 2;
        }
        else
        {
            smallest = 2*i + 2;
            biggest = 2*i + 1;
        }
        if(boxes[i].size < boxes[biggest].size)
        {
            swapper(i, biggest);
            i = biggest;
        }
        else if(boxes[i].size < boxes[smallest].size)
        {
            swapper(i, smallest);
            i = smallest;
        }
        else return;
    }
}

void Heap::heapify()
{
    int i = (num / 2) - 1;
    while( i >= 0)
    {
        siftDown(i--);
    }
}

void Heap::print()
{
    cout << "----------------------------------------"<< endl;
    for(int i = 0; i < num; ++i)
    {
        cout << boxes[i].number <<" " << boxes[i].size << endl;
    }
    cout << "----------------------------------------"<< endl;
}

void Heap::sort()
{
    Box* tempBoxes = new Box[num];
    int cntr = num, i = 0;
    while(i < cntr)
    {
        tempBoxes[i++] = extractMax();
    }
    delete[] boxes;
    num = cntr;
    boxes = tempBoxes;
}

void Heap::printNumbers()
{
    for(int i = num - 1; i >= 0 ; --i)
    {
        cout << boxes[i].number <<" ";
    }
}

Box Heap::extractMax()
{
    Box temp = boxes[0];
    boxes[0] = boxes[--num];
    siftDown(0);
    return temp;
}

int main()
{
    int n = 0;
    cin >> n;
    const int dimens = 3;
    int tempArr[dimens];
    int sumArr [n] ;
    Box* boxes= new Box [n];
    for(int i = 0; i < n; ++i)
    {
        sumArr[i] = 0;
        for(int k = 0; k < dimens; ++k)
        {
            cin >> tempArr[k];
            if(tempArr[k] > sumArr[i]) sumArr[i] = tempArr[k];
        }
        boxes[i].number = i;
        boxes[i].size = sumArr[i];
    }
    Heap boxesHeap(boxes, n);
    boxesHeap.sort();
    boxesHeap.print();
    boxesHeap.printNumbers();
    return 0;
}

