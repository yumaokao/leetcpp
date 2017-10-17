#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

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

    return 0;
}
