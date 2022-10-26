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
 //剑指 Offer 25. 合并两个排序的链表
 //输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 //输入：1->2->4, 1->3->4
 //输出：1->1->2->3->4->4
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//class Solution { 错误答案
//public:
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        ListNode *curr1 = l1;
//        ListNode *curr2 = l2;
//        ListNode *tmp, *ans;
//        if(curr1 == nullptr) return l2;
//        if(curr2 == nullptr) return l1;
//        if(curr1->val <= curr2->val) ans = l1;
//        else ans = l2;
//        while(curr1){
//            if(curr1->val <= curr2->val){
//                if (curr1->next == nullptr) {
//                    curr1->next = curr2;
//                    break;
//                }
//                tmp = curr1->next;
//                curr1->next = curr2;
//                curr1 = tmp;
//                tmp = curr2->next;
//                curr2->next = curr1;
//                curr2 = tmp;
//            }else{
//                if (curr2->next == nullptr) {
//                    curr2->next = curr1;
//                    break;
//                }
//                tmp = curr2->next;
//                curr2->next = curr1;
//                curr2 = tmp;
//                tmp = curr1->next;
//                curr1->next = curr2;
//                curr1 = tmp;
//            }
//        }
//        return ans;
//    }
//};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dum = new ListNode(0);//关键。设置一个伪节点
        ListNode* cur = dum;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != nullptr ? l1 : l2;
        return dum->next;
    }
};
