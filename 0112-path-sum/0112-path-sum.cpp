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
    bool pathsum(TreeNode* node, int sum){
        if(node==NULL) return false;
        if(node->val==sum&& node->left==NULL &&node->right==NULL ){
            return true;
        }
       return  pathsum(node->left , sum -(node->val))||
        pathsum(node->right , sum -(node->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return pathsum(root,targetSum);
    }
};