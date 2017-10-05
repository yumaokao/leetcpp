#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if (nums.empty())
            return ans;
        if (nums.size() == 1)
            return (nums[0] == target) ? vector<int>({0, 0}) : ans;

        int i = -1;
        int j = nums.size();
        int k = -1;
        while (i < j - 1) {
            k = i + (j - i) / 2;
            if (nums[k] == target)
                break;
            if (nums[k] < target)
                i = k;
            else
                j = k;
        }
        if (nums[k] != target)
            return ans;

        // cout << " i " << i << " j " << j << " k " << k << endl;

        int is = i;
        int ks = k;
        while (is < ks - 1) {
            int s = is + (ks - is) / 2;
            if (nums[s] == target)
                ks = s;
            else
                is = s;
        }
        // cout << " ks " << ks << endl;
        ans[0] = ks;

        int ke = k;
        int je = j;
        while (ke < je - 1) {
            int e = ke + (je - ke) / 2;
            if (nums[e] == target)
                ke = e;
            else
                je = e;
        }
        // cout << " ke " << ke << endl;
        ans[1] = ke;

		return ans;
    }
};

void showAns(vector<int>& nums, int target, vector<int>& ans) {
	cout << target << " in [";
	for (auto n: nums)
		cout << n << ", ";
	cout << "] is at [" << ans[0] << ", " << ans[1] << "]" << endl;
}

int main() {
    Solution s;
	vector<int> nums;
	int target;
	vector<int> ans;

	nums = {};
	target = 5;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {5};
	target = 5;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {5};
	target = 3;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {3, 5};
	target = 1;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {3, 5};
	target = 3;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {3, 5};
	target = 5;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {5, 7, 7, 8, 8, 10};
	target = 5;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {5, 7, 7, 8, 8, 10};
	target = 6;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {5, 7, 7, 8, 8, 10};
	target = 7;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {5, 7, 7, 8, 8, 10};
	target = 8;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {5, 7, 7, 8, 8, 10};
	target = 9;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

	nums = {5, 7, 7, 8, 8, 10};
	target = 10;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

    return 0;
}
