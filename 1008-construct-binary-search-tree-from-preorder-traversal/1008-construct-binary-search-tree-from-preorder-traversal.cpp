class Solution {
public:
    TreeNode* solve(vector<int>& pre, int start, int end) {

        if (start > end) return NULL;

        TreeNode* node = new TreeNode(pre[start]);

        int i = start + 1;

        while (i <= end && pre[i] < node->val) {
            i++;
        }

        node->left = solve(pre, start + 1, i - 1);

        node->right = solve(pre, i, end);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        if (preorder.empty()) return NULL;

        return solve(preorder, 0, preorder.size() - 1);
    }
};