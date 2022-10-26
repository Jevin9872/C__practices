//
// Created by Jev on 2022/10/23.
//
//剑指 Offer 13. 机器人的运动范围
//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
// 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
// 也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
// 但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
//
//输入：m = 2, n = 3, k = 1
//输出：3
#include "string"
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(m<10 && n<10){
            int IdxSum = 0;
            for(char c : to_string(m)) IdxSum += int(c-'0');
            for(char c: to_string(n)) IdxSum += int(c-'0');
            if(IdxSum <= k) return m*n;
        }
        vector<vector<int>> board;
        vector<int> small;
        int i = 0, j = 0;
        for (int j = 0; j < n; j++) {
            small.push_back(0);
        }
        for (int i = 0; i < m; i++) {
            board.push_back(small);
        }
        return backtrack(0, 0, k, m, n, board);
    }
private:
    int ans = 0;
    int backtrack(int i, int j,int k, int m, int n, vector<vector<int>> &board){
        if(i< 0|| j<0 ||i >= m || j >= n) return 0;
        string ii = to_string(i);
        string jj = to_string(j);
        int Indexsum = 0;
        for(char c : ii) Indexsum += int(c - '0');
        for(char c : jj) Indexsum += int(c - '0');
        if(Indexsum > k) return 0;
        if(board[i][j] == 1) return 0;

        board[i][j] = 1;
        ans = (backtrack(i + 1, j, k, m, n, board)+backtrack(i - 1, j, k, m, n,board)
                +backtrack(i, j + 1, k, m, n, board)+backtrack(i, j - 1, k, m, n,board)) + 1;
        return ans;
    }
};
//class Solution{
//public:
//    int movingCount(int m,int n ,int k){
//        int IdxSum = 0;
//        for(char c : to_string(m)) IdxSum += int(c-'0');
//        for(char c: to_string(n)) IdxSum += int(c-'0');
//        if(IdxSum <= k) return m*n;
//
//    }
//};
int main(){
    Solution s;
    cout<<s.movingCount(20,23,8)<<endl;
}