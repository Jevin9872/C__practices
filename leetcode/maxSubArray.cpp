//
// Created by Jev on 2022/10/19.
//
#include "vector"
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp < 0) {
                dp = nums[i];
            } else {
                dp += nums[i];
            }
            if (dp > ans) {
                ans = dp;
            }
        }
        return ans;
    }
};

//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int res = nums[0];
//        for(int i = 1; i < nums.size(); i++) {
//            if(nums[i - 1] > 0) nums[i] += nums[i - 1];
//            if(nums[i] > res) res = nums[i];
//        }
//        return res;
//    }
//};
//
//作者：Krahets
//链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/59h9mr/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。