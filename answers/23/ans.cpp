#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        ListNode* head = new ListNode(-1);  // dummy head

        ListNode* mins = new ListNode(-1);
        for (int i = 0; i < lists.size(); i++) {
            if (mins->next == NULL) {
                mins->next = new ListNode(i);
                continue;
            }
            ListNode* cur = mins;
            while (cur->next) {
                if (lists[i]->val < lists[cur->next->val]->val) {
                    ListNode* nn = new ListNode(i);
                    nn->next = cur->next;
                    cur->next = nn;
                    break;
                }
                cur = cur->next;
            }
            if (cur->next == NULL)
                cur->next = new ListNode(i);
        }
        /* ListNode* cur = mins;
        while (cur->next) {
            cout << " i " << cur->next->val << " val " << lists[cur->next->val]->val << endl;
            cur = cur->next;
        } */
        ListNode* csort = head;
        while (mins->next) {
            int midx = mins->next->val;
            csort->next = lists[midx];
            lists[midx] = lists[midx]->next;
            csort->next->next = NULL;
            ListNode* drop = mins->next;
            mins->next = drop->next;
            delete drop;

            if (lists[midx]) {
                ListNode* cur = mins;
                while (cur->next) {
                    if (lists[midx]->val < lists[cur->next->val]->val) {
                        ListNode* nn = new ListNode(midx);
                        nn->next = cur->next;
                        cur->next = nn;
                        break;
                    }
                    cur = cur->next;
                }
                if (cur->next == NULL)
                    cur->next = new ListNode(midx);
            }

            csort = csort->next;
        }

        return head->next;
    }
};

void showLists(vector<ListNode*>& lists) {
    for (auto l: lists) {
        cout << "[";
        ListNode* n = l;
        while (n) {
            cout << " " << n->val;
            n = n->next;
        }
        cout << " ]" << endl;
    }
}

void showAns(vector<ListNode*>& lists, ListNode* ans) {
	cout << " -> [";
    while (ans) {
        cout << " " << ans->val;
        ans = ans->next;
    }
    cout << " ]" << endl;
}

int main() {
    Solution s;
	ListNode* ans;
	vector<ListNode*> lists;

	ListNode* head;

	head = new ListNode(1);
	head->next = new ListNode(3);
	lists.push_back(head);
	head = new ListNode(2);
	head->next = new ListNode(4);
	lists.push_back(head);
	showLists(lists);
	ans = s.mergeKLists(lists);
	showAns(lists, ans);

    return 0;
}
