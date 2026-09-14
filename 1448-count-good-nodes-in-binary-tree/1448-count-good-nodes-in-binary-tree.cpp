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
    void dfs(TreeNode* node , int maxi , int& count){
        if(node==NULL) return ; 

        if(node->val>=maxi){
            count++;
        }
        maxi=max(maxi, node->val);
        
        dfs(node->left , maxi , count);
        dfs(node->right , maxi , count);
    }
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        int count=0;

        dfs(root , maxi , count);

        return count;
    }
};