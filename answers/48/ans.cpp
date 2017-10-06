#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int k = 0; k < matrix.size() / 2; k++) {
            int s = k;
            int e = matrix.size() - 1 - k;
            int tmp = 0;
            for (int i = 0; i < e - s; i++) {
                // cout << "k " << k << ", s " << s << ", e " << e << ", i " << i << endl;
                tmp = matrix[s][s + i];
                cout << tmp << endl;
                matrix[s][s + i] = matrix[e - i][s];
                matrix[e - i][s] = matrix[e][e - i];
                matrix[e][e - i] = matrix[s + i][e];
                matrix[s + i][e] = tmp;
            }
        }
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
	s.rotate(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({1, 2});
	mat.push_back({4, 5});
	showMat(mat);
	s.rotate(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({1, 2, 3});
	mat.push_back({4, 5, 6});
	mat.push_back({7, 8, 9});
	showMat(mat);
	s.rotate(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({5, 1, 9, 11});
	mat.push_back({2, 4, 8, 10});
	mat.push_back({13, 3, 6, 7});
	mat.push_back({15, 14, 12, 16});
	showMat(mat);
	s.rotate(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({1, 1, 1, 1, 2});
	mat.push_back({4, 5, 5, 6, 2});
	mat.push_back({4, 8, 9, 6, 2});
	mat.push_back({4, 8, 7, 7, 2});
	mat.push_back({4, 3, 3, 3, 3});
	showMat(mat);
	s.rotate(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    mat.clear();
	mat.push_back({2,29,20,26,16,28});
	mat.push_back({12,27,9,25,13,21});
	mat.push_back({32,33,32,2,28,14});
	mat.push_back({13,14,32,27,22,26});
	mat.push_back({33,1,20,7,21,7});
	mat.push_back({4,24,1,6,32,34});
	showMat(mat);
	s.rotate(mat);
	cout << " -> " << endl;
	showMat(mat);
	cout << endl;

    return 0;
}
