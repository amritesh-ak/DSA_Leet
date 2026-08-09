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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        bool foundX=false;
        bool foundY=false;
        vector<int> nodes;
        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) {
                    if (node->left->val == x) {
                        foundX = true;
                        nodes.push_back(node->val);
                    }

                    if (node->left->val == y) {
                        foundY = true;
                        nodes.push_back(node->val);
                    }
                    q.push(node->left);
                }
                if(node->right){
                    if (node->right->val == x) {
                        foundX = true;
                        nodes.push_back(node->val);
                    }

                    if (node->right->val == y) {
                        foundY = true;
                        nodes.push_back(node->val);
                    }
                    q.push(node->right);
                }
            }

            if(foundX!=foundY) return false;
        }
       if (foundX && foundY) {
            if (nodes[0] == nodes[1]) return false; //same parents

            return true;                // different parents
        }
        return false;
    }
};