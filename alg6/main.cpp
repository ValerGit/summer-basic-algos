#include <iostream>

using namespace std;
const int startSize = 1;
const int growFactor = 2;
const int cinBuff = 100;

class Stack
{
public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    void push(int);
    char pop();
    void print();
private:
    void grow();
    char* arr;
    int size;
    int buffSize;
};

Stack::Stack()
{
    buffSize = startSize;
    arr = new char[buffSize];
    size = 0;
}

Stack::Stack(const Stack &obj)
{
    buffSize = size = obj.size;
    char* temp = new char[size];
    for(int i = 0; i < size; ++i)
    {
        temp[i] = obj.arr[i];
    }
    delete[] arr;
    arr = temp;
}

Stack::~Stack()
{
    delete[] arr;
}

void Stack::grow()
{
    buffSize *= growFactor;
    char* temp = new char[buffSize];
    for(int i = 0; i < size; ++i)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

void Stack::push(int n)
{
    if(size == buffSize) grow();
    arr[size++] = n;
}

char Stack::pop()
{
    if(size == 0)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    --size;
    char temp = arr[size];
    char* changed = new char[size];
    for(int i = 0; i < size; ++i)
    {
        changed[i] = arr[i];
    }
    delete[] arr;
    arr = changed;
    return temp;
}

void Stack::print()
{
    cout << "-------------------------------------" << endl;
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    cout << "-------------------------------------" << endl;
}

bool equalWords(char first[], char second[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        if(first[i] != second[i])return false;
    }
    return true;
}

int main()
{
    Stack mine;
    cout << "Enter size of word ";
    int n = 0, i = 0;
    cin >> n;
    char first[n];
    char second[n];
    cout << "Enter first word ";
    while(i < n)
    {
        cin >> first[i++];
    }
    i = 0;
    cout << "Enter second word ";
    while(i < n)
    {
        cin >> second[i++];
    }
    char result[n];
    for(int i = 0; i < n; ++i)
    {
        if(first[i] == second[i])
        {
            result[i] = first[i];
            if(!equalWords(first, result, i+1))
            {
                cout << "NO" <<endl;
                return 0;
            }
        }
        else
        {
            for(int k = i; k < n; ++k)
            {
                if(first[i] == second[k])
                {
                    result[i++] = second[k];
                    while(i <= k)
                    {
                        result[i] = mine.pop();
                        if(result[i++] == -1)
                        {
                            cout << "NO" <<endl;
                            return 0;
                        }
                    }
                    i = k;
                    if(equalWords(first, result, k+1)) break;
                    else
                    {
                        cout <<"NO" <<endl;
                        return 0;
                    }
                }
                else mine.push(second[k]);
            }
        }
    }
    cout <<"YES" <<endl;
    return 0;
}

