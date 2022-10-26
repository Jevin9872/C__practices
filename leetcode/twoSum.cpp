//
// Created by Jev on 2022/10/22.
//
//剑指 Offer 57. 和为 s 的两个数字
//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

//输入：nums = [2,7,11,15], target = 9
//输出：[2,7] 或者 [7,2]
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int i = 0, j = nums.size() - 1;
        while(nums[j] > target) j--;
        while (i < j) {
            if(target - nums[j] < nums[i]) j--;
            else if(target - nums[j] > nums[i]) i++;
            else break;
        }
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
        return ans;
    }
};