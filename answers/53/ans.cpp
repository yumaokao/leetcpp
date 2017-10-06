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
    int maxSubArray(vector<int>& nums) {
	    // {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	    // {-2, 1, -2, 4,  3, 5, 6, 1, 5};
        int sum = nums[0];
        int allmax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0)
                sum = 0;
            sum += nums[i];
            if (allmax < sum)
                allmax = sum;
        }
		return allmax; 
    }
};

void showAns(vector<int>& nums, double ans) {
	cout << "[";
	for (auto n: nums)
		cout << " " << n;
	cout << " ] -> " << ans << endl;;
}

int main() {
    Solution s;
	vector<int> nums;
	int ans;

	nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	ans = s.maxSubArray(nums);
	showAns(nums, ans);

	nums = {-2};
	ans = s.maxSubArray(nums);
	showAns(nums, ans);

	nums = {-2, 1};
	ans = s.maxSubArray(nums);
	showAns(nums, ans);

	nums = {-2, 1, -3};
	ans = s.maxSubArray(nums);
	showAns(nums, ans);

	nums = {-2, 1, -3, 4};
	ans = s.maxSubArray(nums);
	showAns(nums, ans);

	nums = {-2, 1, -3, 4, -1, 2};
	ans = s.maxSubArray(nums);
	showAns(nums, ans);

	nums = {-2, -1};
	ans = s.maxSubArray(nums);
	showAns(nums, ans);

    return 0;
}
