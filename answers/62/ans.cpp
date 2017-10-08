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
    int uniquePaths(int m, int n) {
        int cols = max(m, n);
        int rows = min(m, n);
        vector<int> a;
        for (int i = 0; i < cols; i++)
            a.push_back(1);
        for (int j = 1; j < rows; j++) {
            int l = a[0];
            for (int i = 1; i < cols; i++) {
                a[i] += l;
                l = a[i];
            }
        }
        /* for (int i = 0; i < cols; i++)
            cout << a[i] << endl; */
        return a[cols - 1];
    }
};

void showAns(int m, int n, int ans) {
	cout << "m = " << m << ", n = " << n << " -> " << ans << " paths" << endl;
}

int main() {
    Solution s;
	int m, n;;
	int ans;

	m = 1;
	n = 2;
	ans = s.uniquePaths(m, n);
	showAns(m, n, ans);

	m = 3;
	n = 7;
	ans = s.uniquePaths(m, n);
	showAns(m, n, ans);

	m = 1;
	n = 1;
	ans = s.uniquePaths(m, n);
	showAns(m, n, ans);

	m = 3;
	n = 8;
	ans = s.uniquePaths(m, n);
	showAns(m, n, ans);

	m = 2;
	n = 2;
	ans = s.uniquePaths(m, n);
	showAns(m, n, ans);

	m = 2;
	n = 3;
	ans = s.uniquePaths(m, n);
	showAns(m, n, ans);

	m = 3;
	n = 3;
	ans = s.uniquePaths(m, n);
	showAns(m, n, ans);

    return 0;
}
