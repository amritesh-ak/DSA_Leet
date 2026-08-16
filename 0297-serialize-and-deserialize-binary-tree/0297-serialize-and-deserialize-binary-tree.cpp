/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.

    void preorder(TreeNode* node, string& ans) {
        if (node == NULL) {
            ans += "null,";
            return;
        }

        ans += to_string(node->val) + ",";
        preorder(node->left,ans);
        preorder(node->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans;
        preorder(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* solve(vector<string>& tokens, int& i) {

        // If we reach #, this node is NULL
        if (tokens[i] == "null") {
            i++;
            return NULL;
        }

        // Create current node
        TreeNode* node = new TreeNode(stoi(tokens[i]));
        i++;

        // Preorder: root -> left -> right
        node->left = solve(tokens, i);
        node->right = solve(tokens, i);

        return node;
    }


    TreeNode* deserialize(string data) {

        stringstream ss(data);
        string token;

        vector<string> tokens;

        // Separate string using ','
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        int i = 0;

        return solve(tokens, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));