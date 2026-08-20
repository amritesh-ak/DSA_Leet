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
    // the main question is to save space !
    void inorder(TreeNode* node , int& count,int &ans , int k){
        if(node==NULL) return;

        inorder(node->left,count,ans,k);
        count++;
        if(count==k) {
            ans=node->val;
            return;
        }
        inorder(node->right,count,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int count=0;
        inorder(root , count ,ans , k);
        return ans;
    }
};