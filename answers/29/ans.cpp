#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (divisor == 0)
            return (dividend > 0) ? INT_MAX : INT_MIN;
        bool isminus = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            isminus = true;

        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return (dividend == INT_MIN) ? INT_MAX : -dividend;

        dividend = (dividend < 0) ? dividend : -dividend;
        divisor = (divisor < 0) ? divisor : -divisor;
        // cout << dividend << endl;
        // cout << divisor << endl;
        int d = 0;
        while (dividend <= divisor) {
            int ntimes = 1;
            int ndivs = divisor;
            while (dividend <= ndivs && ndivs < 0) {
                // cout << ndivs << endl;
                dividend -= ndivs;
                d += ntimes;
                ndivs = ndivs << 1;
                ntimes = ntimes << 1;
            }
            /* dividend -= ndivs;
            d += ntimes; */
        }
        return (isminus) ? -d : d;
    }
};

int main() {
    Solution s;
	int ans;

	ans = s.divide(1, 1);
	cout << 1 << "/" << 1 << " = " << ans << endl;

	ans = s.divide(0, 1);
	cout << 0 << "/" << 1 << " = " << ans << endl;

	ans = s.divide(2, 1);
	cout << 2 << "/" << 1 << " = " << ans << endl;

	ans = s.divide(4, 2);
	cout << 4 << "/" << 2 << " = " << ans << endl;

	ans = s.divide(7, 2);
	cout << 7 << "/" << 2 << " = " << ans << endl;

	ans = s.divide(1, 0);
	cout << 1 << "/" << 0 << " = " << ans << endl;

	ans = s.divide(-1, 0);
	cout << -1 << "/" << 0 << " = " << ans << endl;

	ans = s.divide(-1, 1);
	cout << -1 << "/" << 1 << " = " << ans << endl;

	ans = s.divide(-2, 1);
	cout << -2 << "/" << 1 << " = " << ans << endl;

	ans = s.divide(-3, 2);
	cout << -3 << "/" << 2 << " = " << ans << endl;

	ans = s.divide(-1, -1);
	cout << -1 << "/" << -1 << " = " << ans << endl;

	ans = s.divide(-2, -1);
	cout << -2 << "/" << -1 << " = " << ans << endl;

	ans = s.divide(-3, -2);
	cout << -3 << "/" << -2 << " = " << ans << endl;

	ans = s.divide(INT_MIN, -1);
	cout << INT_MIN << "/" << -1 << " = " << ans << endl;

	ans = s.divide(INT_MIN, -2);
	cout << INT_MIN << "/" << -2 << " = " << ans << endl;

	ans = s.divide(INT_MAX, -1);
	cout << INT_MAX << "/" << -1 << " = " << ans << endl;

	ans = s.divide(INT_MIN, 2);
	cout << INT_MIN << "/" << 2 << " = " << ans << endl;

#if 0
    cout << ((INT_MIN) << 1 ) << endl;
    cout << ((INT_MIN / 2) << 1 ) << endl;
    cout << ((INT_MIN) << 2 ) << endl;
    cout << ((INT_MIN / 2) << 2 ) << endl;
    cout << ((INT_MAX) << 1 ) << endl;
#endif

	ans = s.divide(INT_MIN, INT_MIN);
	cout << INT_MIN << "/" << INT_MIN << " = " << ans << endl;

	ans = s.divide(INT_MAX, INT_MAX);
	cout << INT_MAX << "/" << INT_MAX << " = " << ans << endl;

	ans = s.divide(INT_MAX, INT_MIN);
	cout << INT_MAX << "/" << INT_MIN << " = " << ans << endl;

	ans = s.divide(INT_MIN, INT_MAX);
	cout << INT_MIN << "/" << INT_MAX << " = " << ans << endl;

    return 0;
}
