/*
    Given an integer n, return true if it is a power of four.
    Otherwise, return false.

    An integer n is a power of four if there exists an integer x such that:

    n = 4^x
*/

#include <iostream>
using namespace std;

bool PowerOfFour(int n)
{
    if(n == 1)
    {
        return true;
    }

    if(n <= 0 || n % 4 != 0)
    {
        return false;
    }

    return PowerOfFour(n / 4);
}

int main()
{
    int n;

    cout << "Enter a number : " << endl;
    cin >> n;

    bool ans = PowerOfFour(n);

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