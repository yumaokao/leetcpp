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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       	vector<int> r; 
		return r;
    }
};

void showAns(vector<vector<int>>& matrix, vector<int>& ans) {
	cout << "{" << endl;
	for (auto r: matrix) {
		cout << " [";;
		for (auto c: r)
			cout << " " << c;
		cout << " ]" << endl;
    }
	cout << "} -> [";
    for (auto a: ans)
        cout << " " << a;
	cout << " ]" << endl;
}

int main() {
    Solution s;
	vector<vector<int>> matrix;
	vector<int> ans;

	matrix.push_back({1, 2, 3});
	matrix.push_back({4, 5, 6});
	matrix.push_back({7, 8, 9});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    return 0;
}
