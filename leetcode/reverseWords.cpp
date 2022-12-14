//
// Created by Jev on 2022/10/22.
//
//剑指 Offer 58 - I. 翻转单词顺序
//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
// 例如输入字符串"I am a student. "，则输出"student. a am I"

//输入: "the sky is blue"
//输出: "blue is sky the"

//输入: " hello world! "
//输出:"world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

//输入: "a good    example"
//输出:"example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。


#include "string"
#include "stack"
#include "vector"
#include "iostream"
using namespace std;
class Solution {
private:
    stack<string> stk;
public:
    string reverseWords(string s) {
        s += ' ';
        string ans;
        string in;
        for (char c: s) {
            if(c != ' '){
                in += c; //凑子字符串
            }else if(stk.empty() && !in.empty()){
                stk.push(in);
                in.clear();
            } else if(!in.empty()){
                stk.push(" ");
                stk.push(in);
                in.clear();
            }
        }
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main(){
    Solution s;
    string cent = "  hello world!  ";
    cout<<s.reverseWords(cent)<<endl;
}