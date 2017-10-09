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
#if 0
        if (n < 4)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
#endif
        if (n < 3)
            return n;
        n -= 2;
        int p1 = 2;
        int p2 = 1;
        int c = 0;
        while (n > 0) {
            c = p2 + p1;
            n--;
            p2 = p1;
            p1 = c;
        }
        return c;
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

	n = 1;
	ans = s.climbStairs(n);
	showAns(n, ans);

	n = 2;
	ans = s.climbStairs(n);
	showAns(n, ans);

	n = 3;
	ans = s.climbStairs(n);
	showAns(n, ans);

	n = 4;
	ans = s.climbStairs(n);
	showAns(n, ans);

	n = 5;
	ans = s.climbStairs(n);
	showAns(n, ans);

	n = 6;
	ans = s.climbStairs(n);
	showAns(n, ans);

	n = 44;
	ans = s.climbStairs(n);
	showAns(n, ans);

	/* n = INT_MAX;
	ans = s.climbStairs(n);
	showAns(n, ans); */

    return 0;
}
