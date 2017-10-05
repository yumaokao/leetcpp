#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       	vector<int> ans = {-1, -1}; 
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

	nums = {5, 7, 7, 8, 8, 10};	
	target = 8;
	ans = s.searchRange(nums, target);
	showAns(nums, target, ans);

    return 0;
}
