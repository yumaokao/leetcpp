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
        vector<int> results;
        int rows = matrix.size();
        if (rows == 0)
            return results;
        int cols = matrix[0].size();
        if (cols == 0)
            return results;

        if (rows == 1)
            return matrix[0];
        if (cols == 1) {
            for (auto m: matrix)
                results.push_back(m[0]);
            return results;
        }

        int d = 0;
        while (cols > 2 * d && rows > 2 * d) {
            int cs = d;
            int ce = cols - d;
            int rs = d;
            int re = rows - d;
            // cout << "cs " << cs << " ce " << ce << " rs " << rs << " re " << re << endl;
            for (int i = cs; i < ce - 1; i++)
                results.push_back(matrix[rs][i]);
            for (int j = rs; j < re - 1; j++)
                results.push_back(matrix[j][ce - 1]);
            for (int i = ce - 1; i > cs; i--)
                results.push_back(matrix[re - 1][i]);
            for (int j = re - 1; j > rs; j--)
                results.push_back(matrix[j][cs]);
            d++;
        }
        if (cols == rows && (rows % 2) == 1)
            results.push_back(matrix[rows / 2][cols / 2]);
		return results;
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
	cout << " ] (" << ans.size() << ")" << endl;
}

int main() {
    Solution s;
	vector<vector<int>> matrix;
	vector<int> ans;

    matrix.clear();
	matrix.push_back({1, 2, 3});
	matrix.push_back({4, 5, 6});
	matrix.push_back({7, 8, 9});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1, 2, 3, 4});
	matrix.push_back({5, 6, 7, 8});
	matrix.push_back({9, 10, 11, 12});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1, 2, 3});
	matrix.push_back({4, 5, 6});
	matrix.push_back({7, 8, 9});
	matrix.push_back({10, 11, 12});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1, 2, 3, 4, 5});
	matrix.push_back({6, 7, 8, 9, 10});
	matrix.push_back({11, 12, 13, 14, 15});
	matrix.push_back({16, 17, 18, 19, 20});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1, 2, 3, 4, 5});
	matrix.push_back({6, 7, 8, 9, 10});
	matrix.push_back({11, 12, 13, 14, 15});
	matrix.push_back({16, 17, 18, 19, 20});
	matrix.push_back({21, 22, 23, 24, 25});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1, 2});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1, 2, 3});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1});
	matrix.push_back({2});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1});
	matrix.push_back({2});
	matrix.push_back({3});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    matrix.clear();
	matrix.push_back({1, 2});
	matrix.push_back({3, 4});
	ans = s.spiralOrder(matrix);
	showAns(matrix, ans);

    return 0;
}
