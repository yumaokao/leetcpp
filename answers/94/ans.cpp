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
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> r;
		if (root == NULL)
			return r;
		if (root->left != NULL)
			r = inorderTraversal(root->left);
		r.push_back(root->val);
		if (root->right != NULL) {
			vector<int> rr = inorderTraversal(root->right);
			r.reserve(rr.size() + r.size());
			r.insert(r.end(), rr.begin(), rr.end());
		}
		return r; 
    }
};

void showAns(TreeNode* root, vector<int> ans) {
	cout << "inorder -> [";
	for (auto a: ans)
		cout << " " << a;
	cout << " ]" << endl;
}

int main() {
    Solution s;
	vector<int> ans;
	
	TreeNode* head = new TreeNode(1);
	head->right = new TreeNode(2);
	head->right->left = new TreeNode(3);
	ans = s.inorderTraversal(head);
	showAns(head, ans);

    return 0;
}
