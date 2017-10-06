#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		return false; 
    }
};

void showAns(string s, string p, bool ans) {
    cout << "[" << s << "], [" << p << "] ";
    cout << ((ans) ? "is" : "is not") << " matched" << endl;
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

    return 0;
}
