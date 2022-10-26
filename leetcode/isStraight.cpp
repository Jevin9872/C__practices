//
// Created by Jev on 2022/10/25.
//
//剑指 Offer 61. 扑克牌中的顺子
// 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
//输入: [1,2,3,4,5]
//输出: True
//
//输入: [0,0,1,2,5]
//输出: True
#include "vector"
#include "unordered_map"
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int joker = 0, big = 0, small = 14, sub = 0;
        unordered_map<int, int> counts;
        for (int i = 0; i < 5; ++i) {
            if (nums[i] == 0){
                joker++;
                continue;
            }
            counts[nums[i]] += 1;
            if(counts[nums[i]] == 2) return false;
            if(nums[i] > big) big = nums[i];
            if(nums[i] < small) small = nums[i];
        }
        sub = max(abs(big - small) - 1,sub);

        if(joker >= sub) return true;
        if(sub == 3) return true;
        return false;
    }
};