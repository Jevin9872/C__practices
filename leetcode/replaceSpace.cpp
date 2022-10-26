//
// Created by Jev on 2022/10/13.
//
/*
 * 输入：s = "We are happy."
 * 输出："We%20are%20happy."
 */
#include "string"
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        for (int i = 0; i < len; i++) {
            if(s[i] == ' ') count++;
        }
//        for (char c : s) {
//            if (c == ' ') count++;
//        }
        //修改字符大小
        s.resize(len +2 * count);

        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
            if(s[i] != ' '){
                s[j] = s[i];
            } else {
                s[j-2] = '%';
                s[j-1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};