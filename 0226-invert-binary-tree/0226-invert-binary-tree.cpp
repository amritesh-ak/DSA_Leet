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
    void invert(TreeNode* node){
        if(!node) return ;

        if(node->left) invert(node->left);
        if(node->right) invert(node->right);

        TreeNode*store=node->left;
        node->left=node->right;
        node->right=store;

        return ;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        invert(root);
        return root;
    }
};