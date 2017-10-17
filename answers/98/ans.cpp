#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValid(TreeNode* root, bool bmax, int vmax, bool bmin, int vmin) {
		bool r = true;
		if (root->left != NULL) {
			if (root->left->val >= root->val || root->left->val < vmin)
				return false;
			if (bmin && root->left->val <= vmin)
				return false;
			if (isValid(root->left, true, root->val, bmin, vmin) == false)
				return false;
		}
		if (root->right != NULL) {
			if (root->right->val <= root->val || root->right->val > vmax)
				return false;
			if (bmax &&root->right->val >= vmax)
				return false;
			if (isValid(root->right, bmax, vmax, true, root->val) == false)
				return false;
		}
       	return true; 
	}

    bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		return isValid(root, false, INT_MAX, false, INT_MIN);
    }
};

void showTree(TreeNode* root) {
    if (root == NULL)
        return;
    queue<TreeNode*> q;
    queue<TreeNode*> nq;
    q.push(root);
    if (root->left)
        nq.push(root->left);
    if (root->right)
        nq.push(root->right);
    cout << "[" << root->val << "]" << endl;
    while(nq.size() > 0) {
        q = nq;
        nq = {};
        while(!q.empty()) {
            TreeNode* n = q.front();
            cout << " [" << n->val << "]";
            if (n->left)
                nq.push(n->left);
            if (n->right)
                nq.push(n->right);
            q.pop();
        }
        cout << endl;
    }
}

void showAns(TreeNode* root, bool ans) {
    showTree(root);
	cout << "isBST -> " << ((ans) ? "Yes" : "No") << endl;
}

int main() {
    Solution s;
	bool ans;
	
	TreeNode* head = new TreeNode(2);
	head->left = new TreeNode(1);
	head->right = new TreeNode(3);
	ans = s.isValidBST(head);
	showAns(head, ans);

	head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	ans = s.isValidBST(head);
	showAns(head, ans);

	head = new TreeNode(6);
	head->left = new TreeNode(2);
	head->left->left = new TreeNode(1);
	head->left->right = new TreeNode(7);
	head->right = new TreeNode(8);
	ans = s.isValidBST(head);
	showAns(head, ans);

	head = new TreeNode(6);
	head->left = new TreeNode(2);
	head->left->left = new TreeNode(1);
	head->left->right = new TreeNode(5);
	head->right = new TreeNode(8);
	ans = s.isValidBST(head);
	showAns(head, ans);

	head = new TreeNode(6);
	head->left = new TreeNode(2);
	head->left->left = new TreeNode(1);
	head->left->right = new TreeNode(5);
	head->right = new TreeNode(10);
	head->right->left = new TreeNode(5);
	ans = s.isValidBST(head);
	showAns(head, ans);

	head = new TreeNode(6);
	head->left = new TreeNode(2);
	head->left->left = new TreeNode(1);
	head->left->right = new TreeNode(5);
	head->right = new TreeNode(10);
	head->right->left = new TreeNode(7);
	ans = s.isValidBST(head);
	showAns(head, ans);

	head = new TreeNode(6);
	ans = s.isValidBST(head);
	showAns(head, ans);

	head = new TreeNode(1);
	head->left = new TreeNode(1);
	ans = s.isValidBST(head);
	showAns(head, ans);

	head = new TreeNode(INT_MIN);
	head->right = new TreeNode(INT_MAX);
	ans = s.isValidBST(head);
	showAns(head, ans);

    return 0;
}
