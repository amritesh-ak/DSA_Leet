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
    int countNodes(TreeNode* root) {
        // one solution should be o(N) like do any traversal and increment the counter!
        // but hence problem state us for less than O(N) solution 
        if(root==NULL) return 0;
        
        int lh= findheight_left(root);
        int rh= findheight_right(root);

        if(lh==rh) return (1<<lh)-1;
        return 1+ countNodes(root->left) + countNodes(root->right);
    }

    int findheight_left(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }

    int findheight_right(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
};