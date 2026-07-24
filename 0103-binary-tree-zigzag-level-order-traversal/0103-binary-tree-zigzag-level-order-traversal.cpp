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
void reverse(vector<int>& arr){
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);
        int j=0;

        while(!q.empty()){
            int size=q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                    if(node->left !=NULL) q.push(node->left);
                    if(node->right !=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            if(j%2!=0){
                reverse(level);
            }
            ans.push_back(level);
            j++;
        }

        return ans;
        
    }
};