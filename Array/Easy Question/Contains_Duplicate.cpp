/*
    Given an integer array nums, return true if any value appears at least twice
    in the array, and return false if every element is distinct.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool ContainsDuplicate(vector<int>& nums)
{
    unordered_set<int> seen;

    for(int num : nums)
    {
        if(seen.find(num) != seen.end())
        {
            return true;
        }

        seen.insert(num);
    }

    return false;
}

int main()
{
    vector<int> nums;
    int size;

    cout << "Enter the size of array : " << endl;
    cin >> size;

    cout << "Enter the elements of array :" << endl;
    for(int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    bool ans = ContainsDuplicate(nums);

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
