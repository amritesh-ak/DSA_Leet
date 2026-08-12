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

    TreeNode* solve(vector<int>& preorder, int pre_start , int pre_end,
            vector<int>& inorder , int in_start , int in_end , map<int , int> &inmap){

        if(pre_start>pre_end || in_start>in_end) return NULL;

        TreeNode* root=new TreeNode(preorder[pre_start]); //naya node banakr, next iteration!
        int in_root = inmap[root->val];
        int num_left=in_root-in_start;

        root->left=solve(preorder,pre_start+1, pre_start+num_left , inorder , in_start , in_root-1 , inmap);

        root->right=solve(preorder,pre_start+num_left+1, pre_end , inorder ,in_root +1,in_end , inmap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmap;

        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        
        TreeNode* root= solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);

        return root;
    }
};