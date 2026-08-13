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

    int height_BT(TreeNode* node){
        if(node==NULL) return 0;

        int lh=height_BT(node->left);
        int rh=height_BT(node->right);

        return 1+max(lh,rh);
    }
    int maxDepth(TreeNode* root) {

        // dfs traversal is main one !!! 
        // go to every node and check for left and then right, find the max among them and return with +1;

        return height_BT(root);
        
    }
};