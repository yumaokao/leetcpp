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
        if (x <= 0)
            return 0;

        int t = x;
        int d = 1;
        while (t > 99) {
            t /= 100;
            d *= 10;
        };

        int i = 1;
        for (i = 0; i < 10; i++) {
            if (t < i * i)
                break;
        }
        int up = i * d;
        int down = (i - 1) * d;
        up = (up > 46340) ? 46341 : up;
        // cout << " t " << t << " i " << i << " up " << up  << " down " << down << endl;;

        while (down < up - 1) {
            int mid = (up - down) / 2 + down;
            // cout << "  up " << up  << " down " << down << endl;;
            if (mid * mid == x)
                return mid;
            if (mid * mid > x)
                up = mid;
            else
                down = mid;
        }

        return down;
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

	x = 1;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 2;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 3;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 4;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 9;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 10;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 99;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 100;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8100;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8101;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8280;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8281;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8282;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8463;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8464;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 8465;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 9999;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 999999;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 2147395599;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 2147483647;
	ans = s.mySqrt(x);
	showAns(x, ans);

	x = 1024;
	ans = s.mySqrt(x);
	showAns(x, ans);

    return 0;
}
