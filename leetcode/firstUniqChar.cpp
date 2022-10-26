//
// Created by Jev on 2022/10/15.
//
//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
//输入：s = "abaccdeff"
//输出：'b'
#include "string"
#include "unordered_map"
#include "map"
#include "vector"
using namespace std;

class Solution2{
private:
    unordered_map<char, int> map;
public:
    char firstUniqChar(string s){
        for (char c: s) {
            map[c] = map.find(c) == map.end();
        }

        for (char c: s) {
            if(map[c]) return c;
        }
        return ' ';
    }
};

class Solution3{
private:
    unordered_map<char, int> map;
public:
    char firstUniqChar(string s){
        for (char c: s) {
            map[c] += 1;
        }

        for (char c: s) {
            if(map[c] < 1) return c;
        }
        return ' ';
    }
};
