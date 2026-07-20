class Solution {
public:

    void preorder(vector<int> &ans , TreeNode* root){
        if(root==NULL) return;
        preorder(ans,root->left);
        preorder(ans,root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(ans,root);
        return ans;
    }
};