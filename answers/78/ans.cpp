#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       	vector<vector<int>> r; 
		r.push_back({});
		r.push_back(nums);
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

    return 0;
}
