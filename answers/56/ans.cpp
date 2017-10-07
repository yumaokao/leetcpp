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
    static int istart(Interval& a) { return min(a.start, a.end); }
    static int iend(Interval& a) { return max(a.start, a.end); }
    static bool comp(Interval& a, Interval& b) { return (istart(a) < istart(b)); }

    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        if (intervals.size() <= 1)
            return intervals;

        vector<Interval> r;
        Interval cur = intervals[0];
        for (auto i: intervals) {
            if (cur.start == i.start && cur.end == i.end)
                continue;
            if (istart(i) <= iend(cur)) {
                cur.start = min(istart(cur), istart(i));
                cur.end = max(iend(cur), iend(i));
            } else {
                r.push_back(cur);
                cur = i;
            }
        }
        r.push_back(cur);
        return r;
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

	intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
	ans = s.merge(intervals);
	showAns(intervals, ans);

	intervals = {Interval(8, 10), Interval(2, 6), Interval(1, 3), Interval(15, 18)};
	ans = s.merge(intervals);
	showAns(intervals, ans);

	intervals = {};
	ans = s.merge(intervals);
	showAns(intervals, ans);

	intervals = {Interval(1, 3), Interval(1, 3)};
	ans = s.merge(intervals);
	showAns(intervals, ans);

	intervals = {Interval(-1, 3), Interval(1, 3)};
	ans = s.merge(intervals);
	showAns(intervals, ans);

	intervals = {Interval(-1, -3), Interval(1, 3)};
	ans = s.merge(intervals);
	showAns(intervals, ans);

	intervals = {Interval(-1, -3), Interval(1, 3), Interval(-2, -4)};
	ans = s.merge(intervals);
	showAns(intervals, ans);

    return 0;
}
