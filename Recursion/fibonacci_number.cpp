/*
    The Fibonacci numbers form a sequence such that each number is the sum
    of the two preceding ones, starting from 0 and 1.

    Given n, return the nth Fibonacci number.

    Fibonacci Sequence:
    0, 1, 1, 2, 3, 5, 8, 13, ...
*/

#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    int n;

    cout << "Enter the value of n : " << endl;
    cin >> n;

    int ans = Fibonacci(n);

    cout << "Fibonacci Number : " << ans << endl;

    return 0;
}