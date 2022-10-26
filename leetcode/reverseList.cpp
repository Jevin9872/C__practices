//
// Created by Jev on 2022/10/12.
//
#include <clocale>
#include "stack"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
class Solution {

public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *curr = head;
        while(curr != nullptr){
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};