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
    void preorder(TreeNode* node , vector<string>&ans , string  str){
        if(!node) return ;

        str+=to_string(node->val)+"->";
        if(node->left == NULL && node->right == NULL){
            str.pop_back();
            str.pop_back();
            ans.push_back(str);
            return;
        }
        //int len=str.size();
        preorder(node->left , ans , str);
        
        //str.resize(len);
        preorder(node->right , ans, str);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str= "";
        preorder(root,ans,str);
        return ans; 
    }
};