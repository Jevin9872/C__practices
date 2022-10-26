//
// Created by Jev on 2022/10/22.
//
//剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
//输入：nums = [1,2,3,4]
//输出：[1,3,2,4]
//注：[3,1,2,4] 也是正确的答案之一。
[1,2,3,4,4,5,6,6,7]
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int j = -1; // 用来记录前半部分出现双数的位置
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                if(j == -1 || j > i) j = i;
            } else {
                if(j != -1){
                    swap(nums[i], nums[j]);
                    for (int k = j; k < i; k++) {
                        if(nums[k] % 2 ==0) {
                            j = k;
                            break;
                        } else {
                            j = i;
                        }
                    }
                }
            }
        }
        return nums;
    }
};

//class Solution {
//public:
//    vector<int> exchange(vector<int>& nums)
//    {
//        int i = 0, j = nums.size() - 1;
//        while (i < j)
//        {
//            while(i < j && (nums[i] & 1) == 1) i++;
//            while(i < j && (nums[j] & 1) == 0) j--;
//            swap(nums[i], nums[j]);
//        }
//        return nums;
//    }
//};
//
//作者：Krahets
//链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/5v3rqr/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。