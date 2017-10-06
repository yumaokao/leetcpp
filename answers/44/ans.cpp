#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty()) {
            for (int i = 0; i < p.size(); i++)
                if (p[i] != '*')
                    return false;
            return true;
        }
        if (p.empty())
            return false;

        char c = p[0];
        p = p.substr(1, p.size() - 1);
        if (c == '?' || c == s[0])
            return isMatch(s.substr(1, s.size() - 1), p);

        if (c == '*') {
            while (p.size() > 1 && p[0] == c)
                p = p.substr(1, p.size() - 1);
            if (p.empty())
                return true;
            for (int i = 0; i < s.size(); i++)
                if (isMatch(s.substr(i, s.size() - i), p))
                    return true;
        }

		return false; 
    }
};

void showAns(string s, string p, bool ans) {
    cout << "[" << s << "], [" << p << "] ";
    cout << ((ans) ? "is" : "is not") << " matched (" << ((ans) ? "True" : "False") << ")" << endl;
}

int main() {
    Solution sol;
	string s;
	string p;
	bool ans;

	s = "aa";
	p = "a";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "aa";
	p = "aa";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "aaa";
	p = "aa";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "aa";
	p = "*";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "aa";
	p = "a*";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "ab";
	p = "?*";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "aab";
	p = "c*a*b";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "";
	p = "";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "a";
	p = "";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "";
	p = "a";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "a";
	p = "*a";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "ba";
	p = "*a";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "cba";
	p = "*a";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "ba";
	p = "?a";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "cba";
	p = "?a";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "";
	p = "*";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "";
	p = "?";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

	s = "";
	p = "**";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

    s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    p = "a*******b";
	ans = sol.isMatch(s, p);
	showAns(s, p, ans);

    return 0;
}
