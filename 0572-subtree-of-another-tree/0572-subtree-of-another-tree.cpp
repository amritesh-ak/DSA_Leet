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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;

        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    void dfs(TreeNode* node, TreeNode* sub,int& x){
        if(node==NULL) return ;

        if(x==1) return ;
        if(node->val==sub->val) {
            bool uff = isSameTree(node ,sub );
            if(uff) x=1;
        }

        dfs(node->left , sub , x);
        dfs(node->right , sub , x);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       int x=0;

       dfs(root , subRoot , x);
       return x;
    }
};