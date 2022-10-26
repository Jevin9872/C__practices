//
// Created by Jev on 2022/10/24.
//
//剑指 Offer 36. 二叉搜索树与双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

//特别地，我们希望可以就地完成转换操作。
//当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        recur(root, root);
        return head;
    }
private:
    Node* head;
    void recur(Node* curr, Node* later){
        if(curr == nullptr) return;

        recur(curr->left, curr);
        curr->right = later;
        recur(curr->right, )
    }
};
//class Solution {
//public:
//    Node* treeToDoublyList(Node* root) {
//        if(root == nullptr) return nullptr;
//        dfs(root);
//        head->left = pre;
//        pre->right = head;
//        return head;
//    }
//private:
//    Node *pre, *head;
//    void dfs(Node* cur) {
//        if(cur == nullptr) return;
//        dfs(cur->left);
//        if(pre != nullptr) pre->right = cur;
//        else head = cur;
//        cur->left = pre;
//        pre = cur;
//        dfs(cur->right);
//    }
//};