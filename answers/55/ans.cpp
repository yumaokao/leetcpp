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
    bool canJump(vector<int>& nums) {
        return false;    
    }
};

void showAns(vector<int>& nums, bool ans) {
	cout << "[";;
	for (auto n: nums)
		cout << " " << n;
	cout << " ] -> " << (ans ? "True" : "Fasle") << endl;
}

int main() {
    Solution s;
	vector<int> nums;
	bool ans;

	nums = {2, 3, 1, 1, 4};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {3, 2, 1, 0, 4};
	ans = s.canJump(nums);
	showAns(nums, ans);

    return 0;
}
