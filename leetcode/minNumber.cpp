//
// Created by Jev on 2022/10/25.
//
//剑指 Offer 45. 把数组排成最小的数
//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//输入: [10,2]
//输出: "102"

//输入: [3,30,34,5,9]
//输出: "3033459"

#include "vector"
#include "string"
using namespace std;

class Solution {
private:
    /*
     * 左小右大
     */
    bool compareTwoNums(int a, int b){
        string aa = to_string(a);
        string bb = to_string(b);
        string sum1 = aa+bb;
        string sum2 = bb+aa;
        if(sum1 < sum2) return true;
        else return false;

    }
public:
    string minNumber(vector<int>& nums) {
        string res;
        for (int i = 0; i < nums.size(); i++) {
            if(i == nums.size() - 1) break;
            for (int j = i + 1; j < nums.size(); j++) {
                if(!compareTwoNums(nums[i],nums[j])) swap(nums[i], nums[j]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            res.append(to_string(nums[i]));
        }
        return res;
    }
};

//class Solution {
//public:
//    string minNumber(vector<int>& nums) {
//        vector<string> strs;
//        for(int i = 0; i < nums.size(); i++)
//            strs.push_back(to_string(nums[i]));
//        quickSort(strs, 0, strs.size() - 1);
//        string res;
//        for(string s : strs)
//            res.append(s);
//        return res;
//    }
//private:
//    void quickSort(vector<string>& strs, int l, int r) {
//        if(l >= r) return;
//        int i = l, j = r;
//        while(i < j) {
//            while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j) j--;//右边找第一个比基准小的值
//            while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j) i++;//左边找第一个比基准大的值
//            swap(strs[i], strs[j]);//把比基准l小的放到左边，大的放到右边
//        }
//        swap(strs[i], strs[l]);
//        quickSort(strs, l, i - 1);
//        quickSort(strs, i + 1, r);
//    }
//};
//
//作者：Krahets
//链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/59ceyt/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。