//
// Created by Jev on 2022/10/23.
//
//剑指 Offer 12. 矩阵中的路径
//给定一个m x n 二维字符网格board 和一个字符串单词word 。如果word 存在于网格中，返回 true ；否则，返回 false 。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

//输入：
// board = [["A","B","C","E"],
//          ["S","F","C","S"],
//          ["A","D","E","E"]]
// word = "ABCCED"
//输出：true

#include "vector"
#include "string"
#include "iostream"
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int k = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(i , j, k, board, word)) return true;
            }
        }
        return false;
    }
private:
    bool backtrack(int i, int j, int k, vector<vector<char>>& board, string word){
        int m = board.size();
        int n = board[0].size();
        if (i >= m || j >= n || i < 0 || j < 0) {
            return false;
        }
        bool res = false;
        if(board[i][j] == word[k]){
            if(k == word.size() - 1) return true;
            board[i][j] = ' ';
            k += 1;
            res = backtrack(i + 1, j, k, board, word) || backtrack(i - 1, j, k, board, word)
                  || backtrack(i, j + 1, k, board, word) || backtrack(i, j - 1, k, board, word);
            k -= 1;
            board[i][j] = word[k];
            return res;
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<vector<char>> board = {{ 'A', 'B', 'C', 'E' },{'S', 'F', 'C', 'S'},{ 'A', 'D', 'E', 'E' }};
    string word = "ABCCED";
//    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"] ,["A", "D", "E", "E" ]];
//    board = {{ "A", "B", "C", "E" }, { "S", "F", "C", "S" },{ "A", "D", "E", "E" }}
//    board.push_back({ 'A', 'B', 'C', 'E' });
//    board.push_back({'S', 'F', 'C', 'S'});
//    board.push_back({ 'A', 'D', 'E', 'E' });
    cout<<s.exist(board, word)<<endl;
}

//class Solution {
//public:
//    bool exist(vector<vector<char>>& board, string word) {
//        rows = board.size();
//        cols = board[0].size();
//        for(int i = 0; i < rows; i++) {
//            for(int j = 0; j < cols; j++) {
//                if(dfs(board, word, i, j, 0)) return true;
//            }
//        }
//        return false;
//    }
//private:
//    int rows, cols;
//    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
//        if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
//        if(k == word.size() - 1) return true;
//        board[i][j] = '\0';
//        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
//                      dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
//        board[i][j] = word[k];
//        return res;
//    }
//};
//
//作者：Krahets
//链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/58d5vh/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。