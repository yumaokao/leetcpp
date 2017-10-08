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
    vector<int> plusOne(vector<int>& digits) {
        vector<int> r = digits;
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            // cout << digits[i] << endl;
            if (carry) {
                r[i] = (digits[i] == 9) ? 0 : digits[i] + 1;
                carry = (r[i] == 0);
            } else
                break;
        }
        if (carry)
            r.insert(r.begin(), 1);
        return r;
    }
};

void showAns(vector<int>& digits, vector<int>& ans) {
	cout << "(";
	for (auto d: digits)
		cout << d;
	cout << ") + 1 = (";
	for (auto d: ans)
		cout << d;
	cout << ")" << endl;
}

int main() {
    Solution s;
	vector<int> digits;
	vector<int> ans;

	digits = {0};
	ans = s.plusOne(digits);
	showAns(digits, ans);

	digits = {9};
	ans = s.plusOne(digits);
	showAns(digits, ans);

	digits = {1, 9};
	ans = s.plusOne(digits);
	showAns(digits, ans);

	digits = {9, 8};
	ans = s.plusOne(digits);
	showAns(digits, ans);

	digits = {9, 9};
	ans = s.plusOne(digits);
	showAns(digits, ans);

	digits = {1, 0, 0};
	ans = s.plusOne(digits);
	showAns(digits, ans);

    return 0;
}
