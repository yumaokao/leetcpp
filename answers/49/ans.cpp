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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;
        unordered_map<string, multiset<string>> umap;
        for (auto s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            umap[t].insert(s);
        }
        for (auto m: umap) {
            vector<string> ar;
            for (auto s: m.second)
                ar.push_back(s);
            r.push_back(ar);
        }
        return r;
    }
};

#if 0
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;
        vector<unordered_map<char, int>> umap;
		for (auto s: strs) {
			bool match = false;
			for (int i = 0; i < umap.size(); i++) {
				match = true;
				unordered_map<char, int> lm;
				lm = umap[i];	
				for (auto c: s) {
					if (lm.find(c) == lm.end()) {
						match = false;
						break;
					}
					lm[c] = lm[c] - 1;
                    if (lm[c] == 0)
                        lm.erase(c);
				}
				/* for (auto m: lm) {
					// cout << m.first << " " << m.second << endl;
					if (m.second > 0)
						match = false;
				} */
                if (lm.size() > 0)
                    match = false;
				if (match) {
					r[i].push_back(s);
					break;
				}
			}
			if (match == false) {
				vector<string> nr;
				unordered_map<char, int> nm;

				nr.push_back(s);
				r.push_back(nr);

				for (auto c: s) {
					if (nm.find(c) == nm.end())
						nm[c] = 0;
					nm[c] = nm[c] + 1;
				}
				umap.push_back(nm);
			}
		}
		return r;
    }
};
#endif

void showAns(vector<string>& strs, vector<vector<string>>& ans) {
	cout << "[";
	for (auto s: strs)
		cout << " " << s;
	cout << " ] -> {" << endl;

	for (auto r: ans) {
		cout << "  [";
		for (auto i: r)
			cout << " " << i;
		cout << " ]" << endl;;
	}
	cout << " }" << endl;
}

int main() {
    Solution s;
	vector<string> strs;
	vector<vector<string>> ans;

	strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	ans = s.groupAnagrams(strs);
	showAns(strs, ans);

	strs = {"egg", "eg", "eeg", "gge"};
	ans = s.groupAnagrams(strs);
	showAns(strs, ans);

	strs = {};
	ans = s.groupAnagrams(strs);
	showAns(strs, ans);

	strs = {"egg"};
	ans = s.groupAnagrams(strs);
	showAns(strs, ans);

    return 0;
}
