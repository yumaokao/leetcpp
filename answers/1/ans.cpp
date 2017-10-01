#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        for (int i = 0; i < nums.size(); i++) {
            int b = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (b == nums[j]) {
                    results.push_back(i);
                    results.push_back(j);
                    return results;
                }
            }
        }
    }
};

int main() {
    vector<int> inputs = {2, 7, 11, 15};
	int t = 9;
    Solution s;
    vector<int> r = s.twoSum(inputs, t);
	for (auto i: r)
    	cout << i << endl;
}
