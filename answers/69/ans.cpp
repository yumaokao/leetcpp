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
    int mySqrt(int x) {
        int t = x;
        while (t > 100) {
            t / 100;
        };
        cout << t << endl;;
        return 0;
    }
};

void showAns(int x, int ans) {
	cout << "sqrt(" << x << ") = " << ans << endl;
}

int main() {
    Solution s;
	int x;
	int ans;

	x = 0;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 99;
	ans = s.mySqrt(x);
	showAns(x, ans);

    return 0;
}
