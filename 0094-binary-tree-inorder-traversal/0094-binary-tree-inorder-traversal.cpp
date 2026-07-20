class Solution {
public:

    void preorder(vector<int> &ans , TreeNode* root){
        if(root==NULL) return;
        preorder(ans,root->left);
        ans.push_back(root->val);
        preorder(ans,root->right);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(ans,root);
        return ans;
    }
};