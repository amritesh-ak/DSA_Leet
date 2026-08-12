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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int, int> inmap;

        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        
        TreeNode* root= solve(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmap);

        return root;
    }

    TreeNode* solve(vector<int>& postorder, int post_start , int post_end,
            vector<int>& inorder , int in_start , int in_end , map<int , int> &inmap){

        if(post_start>post_end || in_start>in_end) return NULL;

        TreeNode* root=new TreeNode(postorder[post_end]);
        int in_root = inmap[postorder[post_end]];
        int num_left=in_root-in_start;

        root->left=solve(postorder, post_start,post_start+num_left-1 , inorder , in_start , in_root-1 , inmap);

        root->right=solve(postorder,post_start+num_left, post_end-1 , inorder ,in_root +1,in_end , inmap);

        return root;
    }
};
    
