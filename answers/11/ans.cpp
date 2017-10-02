#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int water = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = (h * (j - i)) > water ? h * (j - i) : water;
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return water;
    }
};

int main() {
	Solution s;
    vector<int> height;
    int out;

    height = {1, 1};
    out = s.maxArea(height);
    cout << out << endl;

    return 0;
}
