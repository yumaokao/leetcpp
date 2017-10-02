/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head;
        if (l1 == NULL and l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        ListNode *cur; 
        cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1)
            cur->next = l1;
        if (l2)
            cur->next = l2;
        return head;
    }
};

ListNode* getListNodeHead(vector<int> inputs) {
    if (inputs.empty())
        return NULL;

    ListNode* head = new ListNode(inputs[0]); 
    ListNode* cur = head;
    for (int i = 1; i < inputs.size(); i++) {
        cur->next = new ListNode(inputs[i]);
        cur = cur->next;
    }
    return head;
}

string listNodeToString(ListNode* node) {
    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return result.substr(0, result.length() - 2);
}

int main() {
    ListNode *l1, *l2, *ret;
    Solution s;

    l1 = getListNodeHead({1, 2, 3, 4, 5});
    l2 = getListNodeHead({6, 7, 8});
    ret = s.mergeTwoLists(l1, l2);
    cout << listNodeToString(ret) << endl;

    ret = s.mergeTwoLists(NULL, NULL);
    cout << listNodeToString(ret) << endl;

    l1 = getListNodeHead({6, 7, 8});
    ret = s.mergeTwoLists(l1, NULL);
    cout << listNodeToString(ret) << endl;

    l2 = getListNodeHead({6, 7, 8});
    ret = s.mergeTwoLists(NULL, l2);
    cout << listNodeToString(ret) << endl;

    l1 = getListNodeHead({1, 3, 5});
    l2 = getListNodeHead({2, 4, 6});
    ret = s.mergeTwoLists(l1, l2);
    cout << listNodeToString(ret) << endl;

    l1 = getListNodeHead({1, 4});
    l2 = getListNodeHead({2, 3, 5, 6});
    ret = s.mergeTwoLists(l1, l2);
    cout << listNodeToString(ret) << endl;

    l1 = getListNodeHead({4});
    l2 = getListNodeHead({1, 2, 3, 5, 6});
    ret = s.mergeTwoLists(l1, l2);
    cout << listNodeToString(ret) << endl;

    l1 = getListNodeHead({1});
    l2 = getListNodeHead({1, 2, 3, 5, 6});
    ret = s.mergeTwoLists(l1, l2);
    cout << listNodeToString(ret) << endl;

    l1 = getListNodeHead({1, 2, 3, 4, 5, 6});
    l2 = getListNodeHead({1, 2, 3, 4, 5, 6});
    ret = s.mergeTwoLists(l1, l2);
    cout << listNodeToString(ret) << endl;

    return 0;
}
