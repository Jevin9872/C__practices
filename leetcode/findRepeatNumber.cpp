//
// Created by Jev on 2022/10/14.
//
/*
 * 输入：[2, 3, 1, 0, 2, 5, 3]
 * 输出：2 或 3
 */
#include "vector"
#include "unordered_map"
#include "iostream"
using namespace std;
class Solution {
private:
    unordered_map<int, int> assist;
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int num: nums) {
            assist[num] += 1;
            if(assist[num] >= 2){
                return num;
            }
        }
        return nums.front();
    }
};


//利用索引
class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};


int main(){
    vector<int> nums = {3, 1, 1, 0};
    Solution s;
//    s.findRepeatNumber(nums);
    cout<<s.findRepeatNumber(nums)<<endl;
}
