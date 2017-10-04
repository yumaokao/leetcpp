#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
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
	
	nums = {4, 5, 6, 7, 0, 1, 2};	
	target = 5;
	ans = s.search(nums, target);
	showAns(nums, target, ans);

    return 0;
}
