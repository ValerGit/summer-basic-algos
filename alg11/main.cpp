#include <iostream>

using namespace std;

struct Point
{
    int place;
    bool isStart = false;
};

void morzh(Point* A,int first,int middle, int last)
{
    if(first >= last) return;
    int size = last - first;
    Point* B = new Point[size];
    int firstIter = 0, secondIter = 0;
    while((first + firstIter < middle) && (middle+ secondIter) < last)
    {
        if(A[first + firstIter].place < A[middle + secondIter].place)
        {
            B[firstIter + secondIter].place = A[first + firstIter].place;
            B[firstIter + secondIter].isStart = A[first + firstIter].isStart;
            ++firstIter;
        }
        else
        {
            B[firstIter + secondIter].isStart = A[middle + secondIter].isStart;
            B[firstIter + secondIter].place = A[middle + secondIter].place;
            ++secondIter;
        }
    }
    while((first + firstIter) < middle)
    {
        B[firstIter + secondIter].place = A[first + firstIter].place;
        B[firstIter + secondIter].isStart = A[first + firstIter].isStart;
        ++firstIter;
    }
    while((middle+ secondIter) < last)
    {
        B[firstIter + secondIter].isStart = A[middle + secondIter].isStart;
        B[firstIter + secondIter].place = A[middle + secondIter].place;
        ++secondIter;
    }
    for(int i = 0; i < size; ++i)
    {
        A[first + i].isStart = B[i].isStart;
        A[first + i].place = B[i].place;
    }
}

void mergeSort(Point* A, int start, int end)
{
    if(start+1 >= end) return;
    int med = (start + end) / 2;
    mergeSort(A, start, med);
    mergeSort(A, med, end);
    morzh(A, start, med, end);
}

int main()
{
    int n = 0;
    cin >> n;
    n *= 2;
    Point* input = new Point[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> input[i].place;
        if(i%2 == 0) input[i].isStart = true;
    }
    mergeSort(input, 0, n);
    if(input[n-1].isStart) return 0;
    int end = input[n-1].place;
    int cntr = 1, sum = 0;
    for(int i = n-2; i >=0 ; --i)
    {
        if(!input[i].isStart)
        {
            if(cntr == 0)
            {
                end = input[i].place;
                ++cntr;
            }
            else ++cntr;
        }
        else
        {
            if(cntr == 1)
            {
                sum += end - input[i].place;
                --cntr;
            }
            else --cntr;
        }
    }
    cout << sum ;
    return 0;
}

