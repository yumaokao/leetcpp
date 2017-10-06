#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void chooseOne(vector<vector<int>>& r, vector<int>& f, vector<int>& n) {
		if (n.empty())
			r.push_back(f);

		for (int i = 0; i < n.size(); i++) {
			vector<int> nn = n;
			vector<int> nf = f;
			nf.push_back(nn[i]);
			nn.erase(nn.begin() + i);
			chooseOne(r, nf, nn);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> r;
		vector<int> f;
		chooseOne(r, f, nums);
       	return r; 
    }
};

void showAns(vector<int>& nums, vector<vector<int>>& ans) {
    cout << "[";
	for (auto i: nums)
		cout << " " << i;
	cout << " ] -> " << ans.size() << endl;
	cout << " {" << endl;
	for (auto r: ans) {
		cout << "  [";
		for (auto i: r)
			cout << " " << i;
		cout << " ]" << endl;;
	}
	cout << " }" << endl;
}

int main() {
    Solution s;
	vector<int> nums;
	vector<vector<int>> ans;

	nums = {1, 2, 3};
	ans = s.permute(nums);
	showAns(nums, ans);

	nums = {1};
	ans = s.permute(nums);
	showAns(nums, ans);

	nums = {1, 2};
	ans = s.permute(nums);
	showAns(nums, ans);

	nums = {1, 2, 3, 4};
	ans = s.permute(nums);
	showAns(nums, ans);

	nums = {1, 2, 3, 0};
	ans = s.permute(nums);
	showAns(nums, ans);

	nums = {1, 2, 3, 4, 5};
	ans = s.permute(nums);
	showAns(nums, ans);

    return 0;
}
