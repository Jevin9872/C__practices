//
// Created by Jev on 2022/10/16.
//
//Definition for a binary tree node.
//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
//    3
//   / \
//  9  20
//    /  \
//   15   7
//结果
//[3,9,20,15,7]
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include "vector"
#include "queue"
#include "deque"
using namespace std;
class Solution {
private:
    vector<int> ans;
    queue<TreeNode*> q;
public:
    vector<int> levelOrder(TreeNode* root) {
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            ans.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return ans
    }
};


//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
//给定二叉树: [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回结果：
//[
//  [3],
//  [9,20],
//  [15,7]
//]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
private:
    vector<vector<int>> ans;
    queue<TreeNode*> q;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return ans;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
// 第三行再按照从左到右的顺序打印，其他行以此类推。
//    3
//   / \
//  9  20
//    /  \
//   15   7
//结果
//[
//  [3],
//  [20,9],
//  [15,7]
//]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution4 {
private:
    vector<vector<int>> ans;
    deque<TreeNode*> q;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return ans;
        q.push_back(root);
        int s = 1;//记录层的位置
        while (!q.empty()) {
            vector<int> tmp;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node;
                if (s % 2 == 0) {
                    //偶数层
                    node = q.back();
                    q.pop_back();
                    tmp.push_back(node->val);
                    if(node->right) q.push_front(node->right);
                    if(node->left) q.push_front(node->left);
                } else {
                    //奇数层
                    node = q.front();
                    q.pop_front();
                    tmp.push_back(node->val);
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                }
            }
            s += 1;
            ans.push_back(tmp);
        }
        return ans;
    }
};