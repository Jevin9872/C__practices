//
// Created by Jev on 2022/10/13.
//
/*
 * 输入: s = "abcdefg", k = 2
 * 输出: "cdefgab"
 */
#include "string"
#include "queue"
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        queue<char> l;
        for (int i = 0, j = n; i < s.size(); i++, j++) {
            if (i < n) {
                l.push(s[i]);
            }
            if(j < s.size()) s[i] = s[j];
            if (i >= s.size() - n) {
                s[i] = l.front();
                l.pop();
            }
        }
        return s;
    }
};

class Solution2 {
public:
    string reverseLeftWords(string str,int n){
        if(str.size()==0) return str;
        string s = str.substr(0,n);
        string res = str.substr(n,str.size()-n) + s;
        return res;
    }
};
