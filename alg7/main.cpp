#include <iostream>
#include <heap.h>

using namespace std;

int main()
{
    int n = 0, k = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cin >> k;
    Heap mine(arr, n);
    int moves = 0;
    while(n > 0)
    {
        int sum = 0, cntr = 0;
        while( ((sum + mine.showElement(cntr)) <= k) && (cntr < n))
        {
            if(mine.showElement(cntr) == 1)
            {
                sum += mine.showElement(cntr);
                mine.deleteElement(cntr);
                --n;
            }
            else sum += mine.showElement(cntr++);
        }
        if(cntr != 0)
        {
            int tempArr[cntr];
            for(int i = 0; i < cntr; ++i)
            {
                int temp = mine.extractMax();
                if(temp % 2 == 0) tempArr[i] = temp / 2;
                else tempArr[i] = (temp / 2) + 1;
            }
            for(int i = 0; i < cntr; ++i)
            {
                mine.insert(tempArr[i]);
            }
        }
        ++ moves;
    }
    cout << moves;
    return 0;
}

