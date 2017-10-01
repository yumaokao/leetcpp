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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* pr = result;
        
        while (p1 != NULL || p2 != NULL) {
            int d1 = (p1 == NULL) ? 0 : p1->val;
            int d2 = (p2 == NULL) ? 0 : p2->val;
            ListNode *nr = new ListNode((d1 + d2 + carry) % 10);
            carry = (d1 + d2 + carry) / 10;
            pr->next = nr;
            pr = nr;
            p1 = (p1 == NULL) ? p1 : p1->next;
            p2 = (p2 == NULL) ? p2 : p2->next;
        }
        if (carry > 0) {
            ListNode *nr = new ListNode(carry);
            pr->next = nr;
        }
        return result->next;
    }
};

string listNodeToString(ListNode* node) {
    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return result.substr(0, result.length() - 2);
}

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    ListNode* ret = Solution().addTwoNumbers(l1, l2);

    string out = listNodeToString(ret);
    cout << out << endl;
    return 0;
}
