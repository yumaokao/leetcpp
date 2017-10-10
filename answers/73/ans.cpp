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
        if (matrix.empty())
            return;
        int rows = matrix.size();
        if (matrix[0].empty())
            return;
        int cols = matrix[0].size();
        vector<bool> zcols(cols);
        for (int j = 0; j < matrix.size(); j++) {
            bool rz = false;
            for (int i = 0; i < matrix[j].size(); i++) {
                if (matrix[j][i] == 0) {
                    zcols[i] = true;
                    rz = true;
                }
            }
            if (rz) {
                for (int i = 0; i < matrix[j].size(); i++)
                    matrix[j][i] = 0;
            }
        }
        for (int i = 0; i < zcols.size(); i++) {
            if (zcols[i]) {
                for (int j = 0; j < matrix.size(); j++)
                    matrix[j][i] = 0;
            }
        }
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

    mat.clear();
	mat.push_back({0});
	showMat(mat);
	s.setZeroes(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({1, 0, 1});
	mat.push_back({1, 0, 1});
	mat.push_back({1, 0, 1});
	showMat(mat);
	s.setZeroes(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({1, 0, 1});
	mat.push_back({1, 1, 1});
	mat.push_back({1, 0, 1});
	showMat(mat);
	s.setZeroes(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({1, 0, 1});
	mat.push_back({1, 1, 1});
	mat.push_back({1, 1, 0});
	showMat(mat);
	s.setZeroes(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({1, 1, 1, 1});
	mat.push_back({1, 1, 0, 0});
	showMat(mat);
	s.setZeroes(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({1, 1, 1, 1, 0});
	mat.push_back({0, 1, 0, 1, 1});
	mat.push_back({0, 0, 0, 1, 1});
	mat.push_back({0, 0, 0, 0, 1});
	mat.push_back({1, 1, 1, 1, 1});
	showMat(mat);
	s.setZeroes(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    return 0;
}
