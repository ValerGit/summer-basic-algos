#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter array size\t";
    cin >> n;
    int k = 0;
    cout << "Enter A array\t";
    int arrA[n];
    while(k < n)
    {
        cin  >> arrA[k++];
    }
    k = 0;
    cout << "Enter B array\t";
    int arrB[n];
    while(k < n)
    {
        cin  >> arrB[k++];
    }
    int i_bestA = 0, i_bestB = 0, biggestA = arrA[0];
    int i = 1, i_biggestA = 0;
    int bestSum = arrA[0] + arrB[0];
    while(i < n)
    {
        if(arrA[i] > biggestA)
        {
            biggestA = arrA[i];
            i_biggestA = i;
        }
        int biggstTemp = biggestA + arrB[i];
        if(biggstTemp > bestSum)
        {
            i_bestA = i_biggestA;
            i_bestB = i;
            bestSum = biggstTemp;
        }
        ++i;
    }

    cout << i_bestA <<" " << i_bestB << endl;
    return 0;
}

