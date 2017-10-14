#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // cout << " nums1.size() " << nums1.size() << endl;
        nums1.resize(m + n);
        // cout << " nums1.size() " << nums1.size() << endl;
        int i = m - 1;
        int j = n - 1;
        while (i > -1 || j > -1) {
            if (j == -1)
                break;
            int n1 = (i > -1) ? nums1[i] : 0;
            int n2 = (j > -1) ? nums2[j] : 0;
            // cout << " i " << i << " n1 " << n1 << " j " << j << " n2 " << n2 << endl;
            if (n1 < n2 || i == -1) {
                nums1[i + j + 1] = n2;
                j--;
            } else {
                nums1[i + j + 1] = n1;
                i--;
            }
        }
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

	nums1 = {1, 3, 5};
	nums2 = {2, 4, 6};
	showNums(nums1);
	showNums(nums2);
	cout << " -> " << endl;
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	showNums(nums1);
	cout << endl;

	nums1 = {1, 2, 3};
	nums2 = {4, 5, 6};
	showNums(nums1);
	showNums(nums2);
	cout << " -> " << endl;
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	showNums(nums1);
	cout << endl;

	nums1 = {};
	nums2 = {4, 5, 6};
	showNums(nums1);
	showNums(nums2);
	cout << " -> " << endl;
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	showNums(nums1);
	cout << endl;

	nums1 = {1, 2, 3};
	nums2 = {};
	showNums(nums1);
	showNums(nums2);
	cout << " -> " << endl;
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	showNums(nums1);
	cout << endl;

	nums1 = {};
	nums2 = {};
	showNums(nums1);
	showNums(nums2);
	cout << " -> " << endl;
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	showNums(nums1);
	cout << endl;

	nums1 = {1};
	nums2 = {};
	showNums(nums1);
	showNums(nums2);
	cout << " -> " << endl;
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	showNums(nums1);
	cout << endl;

	nums1 = {-1, 0, 0, 3, 3, 3};
	nums2 = {1, 2, 2};
	showNums(nums1);
	showNums(nums2);
	cout << " -> " << endl;
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	showNums(nums1);
	cout << endl;


    return 0;
}
