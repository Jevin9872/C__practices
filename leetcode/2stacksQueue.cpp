//
// Created by Jev on 2022/10/11.
//
#include <stack>
class CQueue {
public:
    std::stack<int> A,B;
    CQueue() {
    }

    void appendTail(int value) {
        if(B.empty()){
            A.push(value);
        } else{
            while(!B.empty()){
                A.push(B.top());
                B.pop();
            }
            A.push(value);
        }
    }

    int deleteHead() {
        int tmp;
        if(B.empty() && A.empty()){
            return -1;
        } else{
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
            tmp = B.top();
            B.pop();
            return tmp;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

/*
 * leetcode官方解法
 */

class CQueue2 {
private:
    std::stack<int> inStack, outStack;
    //如果输出栈为空，但是输入栈有值的情况
    void in2out(){
        if(!inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    CQueue() {
    }

    void appendTail(int value) {
        inStack.push()
    }

    int deleteHead() {

    }
};
