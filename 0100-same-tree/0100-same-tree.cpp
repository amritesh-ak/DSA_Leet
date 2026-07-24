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
    void check_p(TreeNode* p,vector<int>& for_p){
        if(p==NULL){
            for_p.push_back('N');
            return;
        }
        for_p.push_back(p->val);
        check_p(p->left,for_p);
        check_p(p->right,for_p);

        return;
    }
    void check_q(TreeNode* q,vector<int>& for_q){
        if(q==NULL) {
            for_q.push_back('N');
            return;
        }
        for_q.push_back(q->val);
        check_q(q->left,for_q);
        check_q(q->right,for_q);

        return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> for_p;
        vector<int> for_q;
        check_p(p,for_p);
        check_q(q,for_q);

        if(for_q==for_p) return true ;

        return false;
    }
};