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
    void sortColors(vector<int>& nums) {
        if (nums.empty())
            return;
        int r = 0;
        int b = nums.size() - 1;
        int i = 0;;
        while (i < b + 1) {
            if (nums[i] == 0) {
                nums[i] = nums[r];
                nums[r] = 0;
                r++;
                i++;
            } else if (nums[i] == 2) {
                nums[i] = nums[b];
                nums[b] = 2;
                b--;
            } else {
                i++;
            }
        }

        // nums[r++] = 0;
        return;
        
    }
};

void showNums(vector<int>& nums) {
	cout << " [";
	for (auto i: nums)
		cout << " " << i;
	cout << " ]" << endl;;
}

int main() {
    Solution s;
	vector<int> nums;

	nums = {0};
	showNums(nums);
	s.sortColors(nums);
	cout << " -> " << endl;
	showNums(nums);
	cout << endl;

	nums = {2, 1, 0};
	showNums(nums);
	s.sortColors(nums);
	cout << " -> " << endl;
	showNums(nums);
	cout << endl;

	nums = {2, 1, 0, 0, 1, 2, 0, 1, 2};
	showNums(nums);
	s.sortColors(nums);
	cout << " -> " << endl;
	showNums(nums);
	cout << endl;

    return 0;
}
