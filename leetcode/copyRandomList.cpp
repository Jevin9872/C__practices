//
// Created by Jev on 2022/10/12.
//

#include <clocale>
#include <map>
#include <stack>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {

public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }
        Node *curr = head;
        while(curr){
            Node *node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
            if(curr->next->next != nullptr){
                curr = curr->next->next;
            } else {
                curr = nullptr;
            }
        }
        Node *curr2 = head;
        while(curr2){
            if(curr2->random != nullptr) {
                curr2->next->random = curr2->random->next;
            } else {
                curr2->next->random = nullptr;
            }
            if(curr2->next->next != nullptr){
                curr2 = curr2->next->next;
            } else {
                curr2 = nullptr;
            }
        }
        Node *ans = head->next;
        Node *curr3 = head;
        while(curr3) {
            Node *node = curr3->next;
            curr3->next = curr3->next->next;

            if(node->next!= nullptr){
                node->next = node->next->next;
            } else {
                node->next = nullptr;
            }
            curr3 = curr3->next;
        }
        return ans;
    }
};

//拼接+分块
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};


//哈希表
class Solution3 {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while(cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while(cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return map[head];
    }
};
