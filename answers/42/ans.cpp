#include <string>
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int r = 0;

        int maxh = INT_MIN; 
        int minh = INT_MAX; 
        for (int i = 0; i < height.size(); i++) {
            maxh = (height[i] > maxh) ? height[i] : maxh;
            minh = (height[i] < minh) ? height[i] : minh;
        }

        // cout << maxh << endl;
        // cout << minh << endl;
        for (int h = minh; h < maxh; h++) {
            int l = -1;
            for (int i = 0; i < height.size(); i++) {
                if (height[i] > h) {
                    // cout << " i: " << i << " l: " << l << endl;
                    if (l >= 0 && i > (l + 1))
                        r += (i - l) - 1;
                    l = i;
                }
            }
            // cout << "h " << h << " -> r " << r << endl;
        }
		return r; 
    }
};

void showAns(vector<int>& height, int ans) {
	cout << "[";
	for (auto n: height)
		cout << " " << n;
	cout << " ] -> " << ans << endl; 
}

int main() {
    Solution s;
	vector<int> height;
	int ans;
	
	height = {};
	ans = s.trap(height);
	showAns(height, ans);

	height = {0,1,0,2,1,0,1,3,2,1,2,1};
	ans = s.trap(height);
	showAns(height, ans);

	height = {2,0,2,1,0,1,3,2,1,2,1};
	ans = s.trap(height);
	showAns(height, ans);

	height = {0,3,0,2,1,0,1,3,2,1,2,1};
	ans = s.trap(height);
	showAns(height, ans);

	height = {3,0,2,1,0,1,3,2,1,2,1};
	ans = s.trap(height);
	showAns(height, ans);

	height = {3};
	ans = s.trap(height);
	showAns(height, ans);

	height = {3, 3};
	ans = s.trap(height);
	showAns(height, ans);

	height = {0, -3, 0};
	ans = s.trap(height);
	showAns(height, ans);

	height = {0, -3, 0, 2, -2, 2};
	ans = s.trap(height);
	showAns(height, ans);

    return 0;
}
