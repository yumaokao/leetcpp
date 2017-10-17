#include <string>
#include <climits>
#include <iostream>
#include <vector>

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
    bool isValid(TreeNode* root, int vmax, int vmin) {
		if (root->left != NULL) {
			if (root->left->val > root->val || root->left->val < vmin)
				return false;
			return isValid(root->left, root->val, vmin);
		}
		if (root->right != NULL) {
			if (root->right->val < root->val || root->right->val > vmax)
				return false;
			return isValid(root->right, vmax, root->val);
		}
       	return true; 
	}

    bool isValidBST(TreeNode* root) {
		if (root == NULL)
       		return false; 
		return isValid(root, INT_MAX, INT_MIN);
    }
};

void showAns(TreeNode* root, bool ans) {
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

    return 0;
}
