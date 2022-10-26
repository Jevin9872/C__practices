//
// Created by Jev on 2022/10/12.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "vector"
#include "stack"

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
    stack<int> S;
    ListNode *cur = nullptr;
public:
    vector<int> reversePrint(ListNode* head) {
        cur = head;
        vector<int> ans;
        while(cur != nullptr){
            S.push(cur->val);
            cur = cur->next;
        }
        while(!S.empty()){
            ans.push_back(S.top());
            S.pop();
        }
        return ans;
    }
};


//递推法
class Solution2 {
public:
    vector<int> reversePrint(ListNode* head) {
        recur(head);
        return res;
    }
private:
    vector<int> res;
    void recur(ListNode* head) {
        if(head == nullptr) return;
        recur(head->next);
        res.push_back(head->val);
    }
};
