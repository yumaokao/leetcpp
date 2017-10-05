#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        if (nums[0] == target)
            return 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] == target)
                return i;
            if (nums[j] == target)
                return j;
            if (i == j - 1)
                break;

            int k = i + (j - i) / 2;
            // cout << "i " << i  << " -> " << nums[i]<< endl;
            // cout << "j " << j  << " -> " << nums[j]<< endl;
            // cout << " k " << k << " -> " << nums[k]<< endl;
            if (nums[i] > nums[k]) {
                if (target > nums[i])
                    j = k;
                else {
                    if (target > nums[k])
                        i = k;
                    else
                        j = k;
                }
            } else {
                if (target > nums[i]) {
                    if (target > nums[k])
                        i = k;
                    else
                        j = k;
                } else {
                    i = k;
                }
            }
        }
        return -1;
    }
};

void showAns(vector<int>& nums, int target, int ans) {
	cout << target << " in [";
	for (auto n: nums)
		cout << n << ", ";
	cout << "] is at " << ans << endl;
}

int main() {
    Solution s;
	vector<int> nums;
	int target;
	int ans;
	
	nums = {};	
	target = 5;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	nums = {1};	
	target = 1;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	nums = {4, 5, 6, 7, 0, 1, 2};	
	target = 3;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	target = 4;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	target = 5;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	target = 6;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	target = 7;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	target = 0;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	target = 1;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	target = 2;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	nums = {14, 15, 16, 17, 0, 1, 2, 3, 4, 5, 6, 7, 8};	
	target = 7;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

	target = 17;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

    return 0;
}
