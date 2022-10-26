//
// Created by Jev on 2022/10/18.
//
//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n级的台阶总共有多少种跳法。
//
//答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1

//输入：n = 2
//输出：2
class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1, sum;
        if(n == 0) return 1;
        if(n == 1) return 1;
        for (int i = 0; i < n; i++) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};