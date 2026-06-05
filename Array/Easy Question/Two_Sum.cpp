/*
        Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target.

        You may assume that each input has exactly one solution, and you may not use the same element twice.

        You can return the answer in any order.

Approach: Brute Force
Time Complexity: O(n²)
Space Complexity: O(1)

*/

#include<iostream>
#include<vector>
using namespace std;
vector<int>TwoSum(vector<int>&nums,int target)
{
    for(int i = 0; i < nums.size(); i++) 
    {

        for(int j = i + 1; j < nums.size(); j++)
        {

            if(nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }

        return {};
}
int main()
{
    vector<int> nums;
    int size;
    cout<<"enter the size of array : "<<endl;
    cin>>size;
    cout<<"enter the element of array :"<<endl;
    for(int i=0;i<size;i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);

    }
    int target;
    cout<<"enter the target Element : "<<endl;
    cin>>target;
    vector<int>ans;
    ans=TwoSum(nums,target);
}
