//
// Created by Jev on 2022/10/21.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstddef>

//输入: head = [4,5,1,9], val = 5
 //输出: [4,1,9]
 //解释: 给定你链表中值为5的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *curr =head;
        ListNode *pre = head;
        if(curr->val == val) head = head->next;
        else curr = head->next;
        while(curr){
            if(curr->val == val) pre->next = curr->next;
            pre = pre->next;
            curr = curr->next;
        }
        return head;
    }
};