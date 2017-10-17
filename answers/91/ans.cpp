#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

//      1, 1, 1,
//-> 1  1, 1+1
//      1, 1, 1,
//->    1, 2, 1+2
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        if (s.size() == 1)
            return (s[0] == '0') ? 0 : 1;
        if (s[0] == '0')
            return 0;
        int n1 = 1;
        int n2 = 1;
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            char p = s[i - 1];
            int n = 0;
            if (c == '0' && p == '0')
                return 0;
            if (c == '0') {
                if (p == '1' || p == '2')
                    n = n2;
                else
                    return 0;
            } else {
                if (p == '1' || (p == '2' && (c > '0' && c < '7'))) {
                    n = n1 + n2;
                } else
                    n = n1;
            }

            n2 = n1;
            n1 = n;
        }
        return n1;
    }
};

#if 0
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        return numDecodingTwoChars(s);
    }
    int numDecodingTwoChars(string s) {
        if (s.empty())
            return 1;

        if (s.size() == 1)
            return (s[0] == '0') ? 0 : 1;

        char c = s[0];
        char n = s[1];
        if (c == '1') {
            if (n == '0')
                return numDecodingTwoChars(s.substr(2, s.size() - 2));
            else
                return numDecodingTwoChars(s.substr(2, s.size() - 2))
                     + numDecodingTwoChars(s.substr(1, s.size() - 1));
        }

        if (c == '2') {
            if (n == '0' || n == '7' || n == '8' || n == '9')
                return numDecodingTwoChars(s.substr(2, s.size() - 2));
            else
                return numDecodingTwoChars(s.substr(2, s.size() - 2))
                     + numDecodingTwoChars(s.substr(1, s.size() - 1));
        }

        if (c == '0' || n == '0')
            return 0;

        return numDecodingTwoChars(s.substr(1, s.size() - 1));
    }
};
#endif

void showAns(string s, int ans) {
	cout << "[" << s << "] -> " << ans << endl;
}

int main() {
    Solution sol;
	string s;
	int ans;

	s = "12";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "1212";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "121212";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "10";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "20";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "30";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "0";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "a";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "100";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "27";
	ans = sol.numDecodings(s);
	showAns(s, ans);

	s = "01";
	ans = sol.numDecodings(s);
	showAns(s, ans);

    return 0;
}
