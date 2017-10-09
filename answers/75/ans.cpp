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

    return 0;
}
