//
// Created by Jev on 2022/10/18.
//
//斐波那契数列
//f(0) = 0, f(1) = 1
//f(n)= f(n-1) + f(n-2)
#include "vector"
#include "iostream"
using namespace std;
class Solution {
private:
    vector<int> dp;
public:
    int fib(int n) {
        int ans = 0;
        dp.push_back(0);
        dp.push_back(1);
        if(n == 0) return 0;
        if(n == 1) return 1;
        for (int i = 2; i <= n; i++) {
            dp.push_back((dp[i - 1] + dp[i - 2])%1000000007);
        }
        ans = dp.back()%1000000007;
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.fib(3)<<endl;
}

//class Solution {
//public:
//    int fib(int n) {
//        int a = 0, b = 1, sum;
//        for(int i = 0; i < n; i++){
//            sum = (a + b) % 1000000007;
//            a = b;
//            b = sum;
//        }
//        return a;
//    }
//};
//
//作者：Krahets
//链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/50fji7/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。