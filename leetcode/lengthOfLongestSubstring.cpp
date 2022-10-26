//
// Created by Jev on 2022/10/20.
//
//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
//输入: "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
#include "string"
#include "unordered_map"
using namespace std;
class Solution {
private:
    unordered_map<char, int> map;
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, tmp = 0, i = -1;
        for (int j = 0; j < s.size(); j++) {
            if(map.find(s[j]) == map.end()) i = -1;
            else i = map.find(s[j])->second;
            map[s[j]] = j;
            tmp = tmp < j - i ? tmp + 1 : j - i;
            ans = max(tmp, ans);
        }
        return ans;
    }
};