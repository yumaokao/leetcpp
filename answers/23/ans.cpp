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
        /* ListNode* cur = mins;
        for (int i = 0; i < lists.size(); i++) {
            cur->next = new ListNode            
        } */
        
        return head->next;
    }
};

void showAns(vector<ListNode*>& lists, ListNode* ans) {
    for (auto l: lists) {
        cout << "[";
        ListNode* n = l;
        while (n) {
            cout << " " << n->val;
            n = n->next;
        }
        cout << " ]" << endl;
    }
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
	ans = s.mergeKLists(lists);
	showAns(lists, ans);

    return 0;
}
