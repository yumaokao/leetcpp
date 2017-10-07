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
        if (nums.empty())
            return false;
        int cur = 0;
        int reach = nums[cur];
        while (reach < nums.size() - 1) {
            int nr = reach;
            for (int i = cur + 1; i < reach + 1; i++)
               nr = max(nr, i + nums[i]);
            // cout << "cur " << cur << " reach " << reach << " nr " << nr << endl;
            if (nr == reach)
                break;
            cur = reach;
            reach = nr;
        }
        // cout << "reach " << reach << endl;
        if (reach < nums.size() - 1)
            return false;
        return true;
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

	nums = {2, 3, 1, 1, 4, 1, 0, 0};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {2, 3, 1, 1, 4, 1, 0};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {3, 2, 1, 0, 4, 1};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {3};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {2, 0, 1, 1, 0};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {2, 2, 0, 1, 0};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {3, 1, 2, 0, 4};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {1, 1, 0, 1};
	ans = s.canJump(nums);
	showAns(nums, ans);

	nums = {1, 2, 3};
	ans = s.canJump(nums);
	showAns(nums, ans);

    return 0;
}
