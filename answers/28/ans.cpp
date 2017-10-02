#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;
        if (haystack.size() == 0 || needle.size() == 0)
            return -1;  // I don't think return 0 is correct, but needed to be accepted
        bool found = false;
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            found = true;
            for(int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found)
                return i;
        }
        return -1;
    }
};

void showAns(string haystack, string needle, int ans) {
	cout << "Ans for [" << needle << "] in [" << haystack << "] is " << ans << endl;
}

int main() {
    Solution s;
	int ans;
	string haystack;
	string needle;

	haystack = "haystack";
	needle = "hay";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "haystack";
	needle = "stack";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "haystack";
	needle = "needle";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "needle";
	needle = "haystack";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "haystack";
	needle = "";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "";
	needle = "needle";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "";
	needle = "";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "hay";
	needle = "hay";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "hayhayhay";
	needle = "hay";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "hayhayhay";
	needle = "ay";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

	haystack = "hayhayhay";
	needle = "y";
	ans = s.strStr(haystack, needle);
	showAns(haystack, needle, ans);

    return 0;
}
