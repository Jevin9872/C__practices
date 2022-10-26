//
// Created by Jev on 2022/10/17.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //    1
//   / \
 //  2   2
// / \ / \
 //3  4 4  3
 //true

 //   1
//   / \
 //  2   2
//   \   \
 //   3    3
 //false
#include "vector"
#include "queue"
#include "stack"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
//
//class Solution {
//private:
//    bool compareSubTree(TreeNode *root1, TreeNode *root2){
//        if(root1 == nullptr && root2 == nullptr) return true;
//        if (root1->left == nullptr && root2->right == nullptr) {
//            if (root1->right == nullptr && root2->left == nullptr) {
//                return true;
//            } else {
//                if (root1->right->val == root2->left->val) {
//                    return compareSubTree(root1->left, root2->right) && compareSubTree(root1->right,root2->left);
//                }
//            }
//        }
//        if(root1->left == nullptr && root2->right == nullptr || root1->right == nullptr && root2->left == nullptr) return true;
//        if(root1->left != nullptr && root1->right != nullptr && root2->left != nullptr && root2->right != nullptr) {
//            if(root1->left->val == root2->right->val && root1->right->val == root2->left->val) {
//                return compareSubTree(root1->left, root2->right) && compareSubTree(root1->right,root2->left);
//            }
//        }
//        return false;
//    }
//public:
//    bool isSymmetric(TreeNode* root) {
//        return compareSubTree(root, root);
//    }
//};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || recur(root->left, root->right);
    }
private:
    bool recur(TreeNode* L, TreeNode* R) {
        if(L == nullptr && R == nullptr) return true;
        if(L == nullptr || R == nullptr || L->val != R->val) return false;
        return recur(L->left, R->right) && recur(L->right, R->left);
    }
};
