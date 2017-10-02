/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        string longstr("");
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < longstr.size(); j++) {
                if (s[i] == longstr[j]) {
                    if (longstr.size() > result)
                        result = longstr.size();
                    longstr = longstr.substr(j + 1, longstr.size() - j - 1);
                }
            }
            longstr += s[i];
        }
        if (longstr.size() > result)
            result = longstr.size();
        return result;
    }
};

int main() {
    Solution sol; 
	string s;
	int out = 0;
	s = "abcabcbb";
    out = sol.lengthOfLongestSubstring(s);
    cout << out << endl;

	s = "bbbbb";
    out = sol.lengthOfLongestSubstring(s);
    cout << out << endl;

	s = "pwwkew";
    out = sol.lengthOfLongestSubstring(s);
    cout << out << endl;
    return 0;
}
