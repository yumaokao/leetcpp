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
    void setZeroes(vector<vector<int>>& matrix) {
        return;    
    }
};

void showMat(vector<vector<int>>& mat) {
	cout << " {" << endl;
	for (auto r: mat) {
		cout << "  [";
		for (auto i: r)
			cout << " " << i;
		cout << " ]" << endl;;
	}
	cout << " }" << endl;
}

int main() {
    Solution s;
	vector<vector<int>> mat;

    mat.clear();
	mat.push_back({1});
	showMat(mat);
	s.setZeroes(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    return 0;
}
