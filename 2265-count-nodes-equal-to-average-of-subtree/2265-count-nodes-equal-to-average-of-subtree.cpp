class Solution {
public:

    pair<int,int> dfs(TreeNode* node, int &ans) {
        if(node == NULL)
            return {0, 0};

        auto left = dfs(node->left, ans);
        auto right = dfs(node->right, ans);

        int sum = left.first + right.first + node->val;
        int count = left.second + right.second + 1;

        if(node->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};