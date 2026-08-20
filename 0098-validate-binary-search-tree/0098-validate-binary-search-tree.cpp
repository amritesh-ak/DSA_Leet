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
    bool solve(TreeNode* node , long long min , long long max){
        if(node==NULL) return true;

        if(node->val <= min || node->val >= max) return false;
        return solve(node->left , min , node->val) 
        && solve(node->right , node->val, max);

    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN , LLONG_MAX);
    }
};