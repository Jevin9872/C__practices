//
// Created by Jev on 2022/10/17.
//
#include <clocale>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//     4
//   /   \
//  2     7
// / \   / \
//1   3 6   9

//输出
//     4
//   /   \
//  7     2
// / \   / \
//9   6 3   1
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#include "vector"
#include "queue"
#include "stack"
using namespace std;
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();
            if (node->left != nullptr) stack.push(node->left);
            if (node->right != nullptr) stack.push(node->right);
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
        return root;
    }
};

class Solution2{
public:
    TreeNode* mirrorTree(TreeNode* root){
        if(root == nullptr) return nullptr;
        TreeNode *tmp = root->right;
        root->right = mirrorTree(root->left);
        root->left = mirrorTree(tmp);
        return root;
    }
};