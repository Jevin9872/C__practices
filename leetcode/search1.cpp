//
// Created by Jev on 2022/10/14.
//
/*
 * 统计一个数字在排序数组中出现的次数
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: 2
 */
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
private:
    unordered_map<int , int> assist;
public:
    int search(vector<int>& nums, int target) {
        for (int num: nums) {
            assist[num] += 1;
        }
        for (auto a: assist) {
            if (a.first == target) {
                return a.second;
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        // 搜索右边界 right
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] <= target) i = m + 1;
            else j = m - 1;
        }
        int right = i;
        // 若数组中无 target ，则提前返回
        if(j >= 0 && nums[j] != target) return 0;
        // 搜索左边界 right
        i = 0; j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] < target) i = m + 1;
            else j = m - 1;
        }
        int left = j;
        return right - left - 1;
    }
};
