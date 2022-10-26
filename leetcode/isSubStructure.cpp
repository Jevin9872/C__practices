//
// Created by Jev on 2022/10/17.
//
//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
//
//B是A的子结构， 即 A中有出现和B相同的结构和节点值。
//给定树a
//     3
//    / \
//   4   5
//  / \
// 1   2
//给定树b
//   4
//  /
// 1
//返回true

#include <clocale>
#include "queue"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
private:
//    TreeNode* fineSame(TreeNode *big, TreeNode *small){
//        if(big == nullptr || small == nullptr) return nullptr;
//        if(big->val == small->val) return big;
//        else return (fineSame(big->left, small)!= nullptr)?fineSame(big->left, small):fineSame(big->right, small);
//    };
    bool checkSame(TreeNode *big, TreeNode *small){
        if(small == nullptr) return true;
        if(big != nullptr && big->val == small->val){
            return checkSame(big->left, small->left) && checkSame(big->right, small->right);
        } else{
            return false;
        }
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        TreeNode *curr1 = A;
        TreeNode *curr2 = B;
        queue<TreeNode *> q;
        bool ans = false;
        if(curr2 == nullptr) return ans;
        q.push(curr1);
        while(!q.empty()){
            if(ans) break;
            TreeNode *tmp = q.front();
            if(tmp->val == curr2->val) ans = checkSame(tmp, curr2);
            q.pop();
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        return ans;
    }
};


//class Solution {
//public:
//    bool isSubStructure(TreeNode* A, TreeNode* B) {
//        return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
//    }
//private:
//    bool recur(TreeNode* A, TreeNode* B) {
//        if(B == nullptr) return true;
//        if(A == nullptr || A->val != B->val) return false;
//        return recur(A->left, B->left) && recur(A->right, B->right);
//    }
//};
