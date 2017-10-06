#include <string>
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	string readDigits(string s) {
		string r("");
		char cur = s[0];
		int times = 1;

        // cout << "s: [" << s << "]" << endl;
		stringstream ss;
		for (int i = 1; i < s.size(); i++) {
			if (cur == s[i]) {
                times++;
				continue;
            }
			ss << times << cur;
			cur = s[i];
			times = 1;
		}
		ss << times << cur;

        string str;
	    ss >> str;
		r += str;
		return r;
	}
    string countAndSay(int n) {
       	string r("");

		if (n < 1)
			return r;
		r += "1";

		while (n-- > 1)
			r = readDigits(r);

		return r;
    }
};

void showAns(int n, string ans) {
	cout << "n = " << n << "-> [" << ans << "]" << endl;
}

int main() {
    Solution s;
	int n;
	string ans;
	
	n = 1;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 2;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 3;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 4;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 5;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 6;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 7;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 8;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 9;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 10;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = 0;
	ans = s.countAndSay(n);
	showAns(n, ans);

	n = -1;
	ans = s.countAndSay(n);
	showAns(n, ans);

    return 0;
}
