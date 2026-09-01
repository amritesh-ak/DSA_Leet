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
    void solve(TreeNode* node , int &ans ,  bool isleft){
        if(!node){
            return;
        }
        if(node->left==NULL && node->right==NULL && isleft){
            ans+=node->val;
        }

        solve(node->left , ans , true);
        solve(node->right,  ans , false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        int ans=0;
        solve(root ,ans, false);

        return ans;
    }
};