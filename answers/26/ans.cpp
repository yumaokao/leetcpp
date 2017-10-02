#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int curidx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[curidx])
                continue;
            nums[++curidx] = nums[i];
        }

       	return curidx + 1; 
    }
};

void showAns(int ans, vector<int>& nums) {
	cout << "Ans " << ans << endl;
	for (auto i: nums)
		cout << " " << i;
	cout << endl;
}

int main() {
    Solution s;
	vector<int> nums;
	int ans;

	nums = {1, 1, 2};
    ans = s.removeDuplicates(nums);
    showAns(ans, nums);

	nums = {1, 1, 1};
    ans = s.removeDuplicates(nums);
    showAns(ans, nums);

	nums = {1, 2, 3, 4, 5, 6};
    ans = s.removeDuplicates(nums);
    showAns(ans, nums);

	nums = {1, 2, 3, 4, 5, 6, 6};
    ans = s.removeDuplicates(nums);
    showAns(ans, nums);

	nums = {};
    ans = s.removeDuplicates(nums);
    showAns(ans, nums);

	nums = {1};
    ans = s.removeDuplicates(nums);
    showAns(ans, nums);

	nums = {1, 2, 2, 2};
    ans = s.removeDuplicates(nums);
    showAns(ans, nums);

    return 0;
}
