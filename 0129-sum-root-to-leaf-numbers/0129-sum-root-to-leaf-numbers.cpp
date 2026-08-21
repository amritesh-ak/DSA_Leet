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
    void solve(TreeNode* node , int num, vector<int>& ans){
        if(node->left == NULL && node->right == NULL){
            ans.push_back(num*10 + node->val);
            return;
        }
        // num=num*10 + node->val;
        if(node->left)solve(node->left,num*10 + node->val ,ans);
        if(node->right)solve(node->right,num*10 + node->val ,ans);
    }
    int sumNumbers(TreeNode* root) {
        int num=0;
        vector<int> ans;
        solve(root,num,ans);

        int sum=0;
        for(int x:ans){
            sum+=x;
        }

        return sum;
    }
};