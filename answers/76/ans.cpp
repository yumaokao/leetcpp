#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        return "";
    }
};

void showAns(string s, string t, string ans) {
	cout << "[" << t << "] in [" << s << "] -> [" << ans << "]" << endl;
}

int main() {
    Solution sol;
	string s;
	string t;
	string ans;

    s = "a";
    t = "a";
	sol.minWindow(s, t);
	showAns(s, t, ans);

    return 0;
}
