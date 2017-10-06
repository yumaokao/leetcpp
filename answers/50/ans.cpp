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
    double myPow(double x, int n) {
		if (n == 0)
			return 1;

		double r = 1.0;
		int nn = (n < 0) ? n : -n;

		double o = (n > 0) ? x : 1 / x;
		int cn = -1;
		while (nn < 0) {
			// cout << "nn " << nn << " cn " << cn << " o " << o << " r " << r << endl;
			if (nn <= cn) {
				r *= o;
				nn -= cn;
				cn = cn << 1;
				o *= o;
			} else {
				o = (n > 0) ? x : 1 / x;
				cn = -1;
			}
		}
		return r;     
    }
};

void showAns(double x, int n, double ans) {
	cout << "( " << x << " ^ "  << n << " ) = " << ans << endl;
}

int main() {
    Solution s;
	double x;
	int n;
	double ans;

	x = 8.88023;
	n = 3;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = 3;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = 4;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = 1;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = 2;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = 0;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = -1;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = -2;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = -3;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = -4;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 10.0;
	n = -4;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 10.0;
	n = -5;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 10.0;
	n = 6;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = INT_MAX;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

	x = 2.0;
	n = INT_MIN;
	ans = s.myPow(x, n);
	showAns(x, n, ans);

    return 0;
}
