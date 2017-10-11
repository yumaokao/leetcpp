#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       	vector<vector<int>> r; 
        if (nums.empty())
            return r;

        int bits = 2 << nums.size() - 1;
        for (int i = 0; i < bits; i++) {
            vector<int> s;
            int n = i;
            int j = 0;
            while (n > 0) {
                if ((n % 2) == 1)
                    s.push_back(nums[j]);
                n = n >> 1;
                j++;
            }
            r.push_back(s);
        }
		return r;
    }
};

void showAns(vector<int>& nums, vector<vector<int>>& ans) {
	cout << "[";
	for (auto n: nums)
		cout << " " << n;
	cout << " ] -> ";
	cout << " {" << endl;
	for (auto r: ans) {
		cout << "  [";
		for (auto i: r)
			cout << " " << i;
		cout << " ]" << endl;
	}
	cout << " }" << endl;
}

int main() {
    Solution s;
	vector<int> nums;
	vector<vector<int>> ans;

	nums = {1, 2, 3};
	ans = s.subsets(nums);
	showAns(nums, ans);

	nums = {};
	ans = s.subsets(nums);
	showAns(nums, ans);

	nums = {1};
	ans = s.subsets(nums);
	showAns(nums, ans);

	nums = {1, 2};
	ans = s.subsets(nums);
	showAns(nums, ans);

	nums = {1, 2, 3, 4};
	ans = s.subsets(nums);
	showAns(nums, ans);

    return 0;
}
