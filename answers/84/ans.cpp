#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		return 0; 
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

    return 0;
}
