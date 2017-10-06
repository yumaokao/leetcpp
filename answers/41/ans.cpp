#include <string>
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /* cout << "[";
        for (auto n: nums)
            cout << " " << n;
        cout << " ] B " << endl; */
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] < 1 || nums[i] > nums.size())
                    break;
                int tmp = nums[nums[i] - 1];
                if (nums[i] == tmp)
                    break;
                nums[nums[i] - 1] = nums[i];
                nums[i] = tmp;
            }
        }
        /* cout << "[";
        for (auto n: nums)
            cout << " " << n;
        cout << " ] A " << endl; */
        int r = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != r)
                break;
            r++;
        }
       	return r; 
    }
};

void showAns(vector<int>& nums, int ans) {
	cout << "[";
	for (auto n: nums)
		cout << " " << n;
	cout << " ] -> " << ans << endl; 
}

int main() {
    Solution s;
	vector<int> nums;
	int ans;
	
	nums = {};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {-2};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {0};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {1};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {2};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {1, 2, 0};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {3, 4, -1, 1};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {4, 5, 1, 2};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {-1, 10, 5, 1};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

	nums = {1, 1};
	ans = s.firstMissingPositive(nums);
	showAns(nums, ans);

    return 0;
}
