#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		return 0; 
    }
};

void showAns(string s, int ans) {
	cout << "[" << s << "] -> " << ans << endl;
}

int main() {
    Solution sol;
	string s;
	int ans;

	s = "AB";
	ans = sol.numDecodings(s);
	showAns(s, ans);

    return 0;
}
