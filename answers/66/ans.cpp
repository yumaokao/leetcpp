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
        return digits;
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

    return 0;
}
