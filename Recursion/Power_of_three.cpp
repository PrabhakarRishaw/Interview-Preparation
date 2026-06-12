/*
    Given an integer n, return true if it is a power of three.
    Otherwise, return false.

    An integer n is a power of three if there exists an integer x such that:

    n = 3^x
*/

#include <iostream>
using namespace std;

bool PowerOfThree(int n)
{
    if(n == 1)
    {
        return true;
    }

    if(n <= 0 || n % 3 != 0)
    {
        return false;
    }

    return PowerOfThree(n / 3);
}

int main()
{
    int n;

    cout << "Enter a number : " << endl;
    cin >> n;

    bool ans = PowerOfThree(n);

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