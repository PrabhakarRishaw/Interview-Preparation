/*
    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
    find two numbers such that they add up to a specific target number.

    Return the indices of the two numbers (1-based indexing) as an integer array [index1, index2].

    You may not use the same element twice.

    There is exactly one solution.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> TwoSumII(vector<int>& numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while(left < right)
    {
        int sum = numbers[left] + numbers[right];

        if(sum == target)
        {
            return {left + 1, right + 1};
        }
        else if(sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return {};
}

int main()
{
    vector<int> numbers;
    int size;

    cout << "Enter the size of array : " << endl;
    cin >> size;

    cout << "Enter the elements of sorted array :" << endl;
    for(int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    int target;
    cout << "Enter the target element : " << endl;
    cin >> target;

    vector<int> ans;
    ans = TwoSumII(numbers, target);

    if(!ans.empty())
    {
        cout << "Indices : " << ans[0] << " " << ans[1] << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
