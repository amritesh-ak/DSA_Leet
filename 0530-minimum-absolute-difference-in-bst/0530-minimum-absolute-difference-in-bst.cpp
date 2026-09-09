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
    void dfs(TreeNode* node , vector<int>& store){
        if(node==NULL){
            return;
        }

        dfs(node->left,store);
        store.push_back(node->val);
        dfs(node->right,store);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        dfs(root , ans);

        int anss=INT_MAX;
        for(int i=1 ; i<ans.size();i++){
            anss=min(anss , abs(ans[i] -ans[i-1]));
        }

        return anss;
    }
};