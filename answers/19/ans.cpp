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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (head == NULL || n <= 0)
                return head;
            if (head->next == NULL && n == 1)
                return NULL;

            int c = 0;
            ListNode *cur = head;
            ListNode *anc = head;
            while (cur != NULL) {
                if (c > n)
                    anc = anc->next;
                else
                    c++;
                cur = cur->next;
            }
            if (c == n)
                head = head->next;
            if (c > n)
                anc->next = anc->next->next;

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
    ListNode *head, *ret;
    Solution s;

    head = getListNodeHead({1, 2, 3, 4, 5});
    ret = s.removeNthFromEnd(head, 2);
    cout << listNodeToString(ret) << endl;

    head = getListNodeHead({1, 2, 3, 4, 5});
    ret = s.removeNthFromEnd(head, 3);
    cout << listNodeToString(ret) << endl;

    head = getListNodeHead({1});
    ret = s.removeNthFromEnd(head, 1);
    cout << listNodeToString(ret) << endl;

    head = getListNodeHead({1});
    ret = s.removeNthFromEnd(head, 3);
    cout << listNodeToString(ret) << endl;

    head = getListNodeHead({1, 2});
    ret = s.removeNthFromEnd(head, 3);
    cout << listNodeToString(ret) << endl;

    head = getListNodeHead({1, 2, 3});
    ret = s.removeNthFromEnd(head, 3);
    cout << listNodeToString(ret) << endl;

    head = getListNodeHead({1, 2, 3, 4});
    ret = s.removeNthFromEnd(head, 3);
    cout << listNodeToString(ret) << endl;

    return 0;
}
