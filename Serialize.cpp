#include <bits/stdc++.h>
using namespace std;
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
string serialize(TreeNode* root) {
        string code;
        dfs(root, code);
        return code;
    }

    void dfs(TreeNode* root, string& code) {
        if(!root) code += "# ";
        else {
            code += to_string(root->val) + ' ';
            dfs(root->left, code);
            dfs(root->right, code);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return decode(data, i);
    }

    TreeNode* decode(string& data, int& i) {
        string val;
        while(data[i] != ' ') val += data[i++];
        
        if(val == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        ++i;
        root->left = decode(data, i);
        ++i;
        root->right = decode(data, i);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));