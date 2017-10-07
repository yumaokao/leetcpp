#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
      	return intervals; 
    }
};

void showAns(vector<Interval>& intervals, vector<Interval>& ans) {
	cout << "[";;
	for (auto i: intervals)
		cout << " (" << i.start << "," << i.end << ")";
	cout << " ] -> [";
	for (auto i: ans)
		cout << " (" << i.start << "," << i.end << ")";
	cout << " ]" << endl;
}

int main() {
    Solution s;
	vector<Interval> intervals;
	vector<Interval> ans;

	intervals = {Interval(1, 3), Interval(2, 6)};
	ans = s.merge(intervals);
	showAns(intervals, ans);

    return 0;
}
