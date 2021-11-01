#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High) 
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size) 
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int Count(int* a, const int size) 
{
    int count = 0;
    for (int i = 0; i < size; i++) 
    {
        if (a[i] < 0 && abs(a[i]) % 2 == 0) 
        {
            count++;
        }
    }
    return count;
}

void Zero(int* a, const int size) 
{
    for (int i = 0; i < size; i++)
        if (a[i] < 0 && abs(a[i]) % 2 == 0)
            a[i] = 0;
}

int Sum(int* a, const int size) 
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (a[i] < 0 && abs(a[i]) % 2 == 0)
            S += a[i];
    return S;
}


int main() 
{
    srand((unsigned)time(NULL));
    const int n = 24;
    int a[n];

    int Low = -15;
    int High = 75;

    Create(a, n, Low, High);
    Print(a, n);

    cout << "Sum = " << Sum(a, n) << endl;
    cout << "Count = " << Count(a, n) << endl;

    Zero(a, n);
    Print(a, n);

    return 0;
}