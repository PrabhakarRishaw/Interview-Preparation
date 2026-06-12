/*
    Given an integer n, return true if it is a power of two.
    Otherwise, return false.

    An integer n is a power of two if there exists an integer x such that:

    n = 2^x
*/

#include <iostream>
using namespace std;

bool PowerOfTwo(int n)
{
    if(n == 1)
    {
        return true;
    }

    if(n <= 0 || n % 2 != 0)
    {
        return false;
    }

    return PowerOfTwo(n / 2);
}

int main()
{
    int n;

    cout << "Enter a number : " << endl;
    cin >> n;

    bool ans = PowerOfTwo(n);

    if(ans)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}