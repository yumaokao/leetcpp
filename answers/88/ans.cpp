#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		return;        
    }
};

void showNums(vector<int>& nums) {
	cout << "[";
	for (auto n: nums)
		cout << " " << n;
	cout << " ]" << endl;
}

int main() {
    Solution s;
	vector<int> nums1;
	vector<int> nums2;

	nums1 = {1, 2, 3};
	nums2 = {4, 5, 6};
	showNums(nums1);
	showNums(nums2);
	cout << " -> " << endl;
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	showNums(nums1);
	cout << endl;


    return 0;
}
