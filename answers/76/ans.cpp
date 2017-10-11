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
    string minWindow(string s, string t) {
        unordered_map<char , int> tmap;
        unordered_map<char , int> curmap;
        for (auto c: t) {
            if (tmap.find(c) == tmap.end()) {
                tmap[c] = 0;
                curmap[c] = 0;
            }
            tmap[c]  = tmap[c] + 1;
        }
        for (auto& m: tmap)
            cout << m.first << " " << m.second << endl;

        int min = INT_MAX;
        int min_i = 0;
        int get = 0;
        int i = -1;
        int j = 0;
        while (j < s.size() || get == t.size()) {
            cout << "i " << i << " j " << j << " get " << get << endl;
            if (get == t.size()) {
                i++;
                cout << "i " << i << " j " << j << endl;
                if (min > (j - i)) {
                    min = j - i ;
                    min_i = i;
                }
                char c = s[i];
                if (tmap.find(c) == tmap.end())
                    continue;
                if (curmap[c] <= tmap[c])
                    get--;
                curmap[c] = curmap[c] - 1;

            } else if (get < t.size()) {
                char c = s[j];
                if (tmap.find(c) == tmap.end()) {
                    j++;
                    continue;
                }
                if (curmap[c] < tmap[c])
                    get++;
                curmap[c] = curmap[c] + 1;
                j++;
            }
        }

        cout << "min_i " << min_i << " min " << min << endl;
        return (min == INT_MAX) ? "" : s.substr(min_i, min);
    }
};

void showAns(string s, string t, string ans) {
	cout << "[" << t << "] in [" << s << "] -> [" << ans << "]" << endl;
}

int main() {
    Solution sol;
	string s;
	string t;
	string ans;

    s = "a";
    t = "a";
	ans = sol.minWindow(s, t);
	showAns(s, t, ans);

    s = "ADOBECODEBANC";
    t = "ABC";
	ans = sol.minWindow(s, t);
	showAns(s, t, ans);

    s = "ADOBECODEBANC";
    t = "ABCA";
	ans = sol.minWindow(s, t);
	showAns(s, t, ans);

    s = "ADOBECODEBANC";
    t = "AF";
	ans = sol.minWindow(s, t);
	showAns(s, t, ans);

    s = "ADOBECODEBANC";
    t = "CE";
	ans = sol.minWindow(s, t);
	showAns(s, t, ans);

    s = "ADOBECODEBANC";
    t = "BD";
	ans = sol.minWindow(s, t);
	showAns(s, t, ans);

    return 0;
}
