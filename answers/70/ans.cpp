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
    int climbStairs(int n) {
		return n;        
    }
};

void showAns(int n, int ans) {
	cout << "(" << n << ") = " << ans << endl;
}

int main() {
    Solution s;
	int n;
	int ans;

	n = 0;
	ans = s.climbStairs(n);
	showAns(n, ans);

    return 0;
}
