#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 1;
        int li = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j] && longest < j - i + 1) {
                    bool isgood = true;
                    for (int k = 0; k < ((j - i) / 2) + 1; k++) {
                        if (s[i + k] != s[j - k])
                            isgood = false;
                    }
                    if (isgood) {
                        longest = j - i + 1;
                        li = i;
                    }
                }
            }
        }
        return s.substr(li, longest);
    }
};

int main() {
    Solution sol; 
	string s;
	string out;

	s = "babad";
    out = sol.longestPalindrome(s);
    cout << out << endl;

	s = "cbbd";
    out = sol.longestPalindrome(s);
    cout << out << endl;

    return 0;
}
