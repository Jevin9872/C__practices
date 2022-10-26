//
// Created by Jev on 2022/10/11.
//
#include "stack"
class MinStack {
private:
    std::stack<int> S, minS;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        S.push(x);
        if(minS.empty()){
            minS.push(x);
        }else{
            if (x < minS.top()) {
                minS.push(x);
            }else{
                minS.push(minS.top());
            }
        }
    }

    void pop() {
        minS.pop();
        S.pop();
    }

    int top() {
        return S.top();
    }

    int min() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */