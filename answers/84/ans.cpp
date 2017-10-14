#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        vector<int> lefts(heights.size());
        vector<int> rights(heights.size());
        lefts[0] = -1;
        rights[heights.size() - 1] = heights.size();
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int l = i - 1;
            while (l > -1) {
                if (heights[l] < h) {
                    lefts[i] = l;
                    break;
                } else {
                    lefts[i] = lefts[l];
                    l = lefts[l];
                }
            }
        }
        for (int i = heights.size() - 1; i > -1; i--) {
            int h = heights[i];
            int r = i + 1;
            while (r < heights.size()) {
                if (heights[r] < h) {
                    rights[i] = r;
                    break;
                } else {
                    rights[i] = rights[r];
                    r = rights[r];
                }
            }
        }
        int largest = 0;
        for (int i = 0; i < heights.size(); i++) {
            // cout << "i " << i << " l " << lefts[i] << " r " << rights[i] << endl;
            // cout << " i " << i << " h " << heights[i] << " w " << rights[i] - lefts[i] - 1 << endl;
            largest = max(heights[i] * (rights[i] - lefts[i] - 1), largest);
        }
		return largest;
    }
};

void showAns(vector<int>& heights, int ans) {
	cout << "[";
	for (auto n: heights)
		cout << " " << n;
	cout << " ] -> " << ans << endl;
}

int main() {
    Solution s;
	vector<int> heights;
	int ans;

	heights = {2, 1, 5, 6, 2, 3};
	ans = s.largestRectangleArea(heights);
	showAns(heights, ans);

	heights = {2, 2, 5, 6, 2, 3};
	ans = s.largestRectangleArea(heights);
	showAns(heights, ans);

	heights = {2, 1, 5, 6, 2, 3, 2};
	ans = s.largestRectangleArea(heights);
	showAns(heights, ans);

	heights = {2, 1, 5, 6, 2, 3, 2, 2};
	ans = s.largestRectangleArea(heights);
	showAns(heights, ans);

	heights = {2, 1, 5, 6, 2, 3, 2, 1};
	ans = s.largestRectangleArea(heights);
	showAns(heights, ans);

	heights = {2};
	ans = s.largestRectangleArea(heights);
	showAns(heights, ans);

	heights = {};
	ans = s.largestRectangleArea(heights);
	showAns(heights, ans);

    return 0;
}
