/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;

        unordered_map<int, int> mpp;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            mpp[node->val]++;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        int maxi = 0;
        for (auto it : mpp) {
            maxi = max(maxi, it.second);
        }

        for (auto it : mpp) {
            if (it.second == maxi) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};