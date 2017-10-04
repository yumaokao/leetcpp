#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        static bool isequal(vector<int>& i, vector<int>& j) {
            /* cout << i.size() << endl;
            cout << " i [" << i[0] << " " << i[1] << " " << i[2] << "]" << endl;
            cout << " j [" << j[0] << " " << j[1] << " " << j[2] << "]" << endl; */
            for (int k = 0; k < i.size(); k++) {
                if (i[k] != j[k])
                    return false;
            }
            return true;
        }

        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int> > results;
            if (nums.size() < 3)
                return results;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    int target = -nums[i] - nums[j];
                    for (int k = j + 1; k < nums.size(); k++) {
                        if (target == nums[k]) {
                            vector<int> r;
                            r.push_back(nums[i]);
                            r.push_back(nums[j]);
                            r.push_back(nums[k]);
                            results.push_back(r);
                            break;
                        }
                    }
                }
            }

            sort(results.begin(), results.end());
            if (results.size() > 1) {
                results.erase(unique(results.begin(), results.end(), isequal),results.end());
            }
            return results;
        }
};

void showAns(vector<vector<int> >& ans) {
    cout << "Ans" << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (auto j: ans[i])
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    vector<int> nums;
    vector<vector<int>> ans;;

    nums = {-1, 0, 1, 2, -1, -4};
    ans = Solution().threeSum(nums);
    showAns(ans);

    nums = {};
    ans = Solution().threeSum(nums);
    showAns(ans);

    nums = {1, 0};
    ans = Solution().threeSum(nums);
    showAns(ans);

    nums = {0, 1, 1};
    ans = Solution().threeSum(nums);
    showAns(ans);

    nums = {0, 0, 0, 0};
    ans = Solution().threeSum(nums);
    showAns(ans);

    nums = {-1, 0, 1, 0};
    ans = Solution().threeSum(nums);
    showAns(ans);

    nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    ans = Solution().threeSum(nums);
    showAns(ans);

    return 0;
}
