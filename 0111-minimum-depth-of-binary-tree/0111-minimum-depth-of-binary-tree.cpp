/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* node) {
        if(!node) return 0;

        int lh = solve(node->left);
        int rh = solve(node->right);

        if(!node->left)
            return rh + 1;

        if(!node->right)
            return lh + 1;

        return min(lh, rh) + 1;
    }

    int minDepth(TreeNode* root) {
        return solve(root);
    }
};