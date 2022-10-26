//
// Created by Jev on 2022/10/24.
//
//剑指 Offer 34. 二叉树中和为某一值的路径
//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//
//叶子节点 是指没有子节点的节点。
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include "vector"
using namespace std;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        backtrack(root, target);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtrack(TreeNode* root, int target){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr && root->val != target) return;

        tmp.push_back(root->val);
        if(target == root->val && root->left == nullptr && root->right == nullptr){
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        backtrack(root->left, target - root->val);
        backtrack(root->right, target - root->val);
        tmp.pop_back();
        return;
    }
};
//class Solution {
//public:
//    vector<vector<int>> pathSum(TreeNode* root, int sum) {
//        recur(root, sum);
//        return res;
//    }
//private:
//    vector<vector<int>> res;
//    vector<int> path;
//    void recur(TreeNode* root, int tar) {
//        if(root == nullptr) return;
//        path.push_back(root->val);
//        tar -= root->val;
//        if(tar == 0 && root->left == nullptr && root->right == nullptr)
//            res.push_back(path);
//        recur(root->left, tar);
//        recur(root->right, tar);
//        path.pop_back();
//    }
//};