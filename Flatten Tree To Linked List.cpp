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

    void toArr(TreeNode* root,vector<int>&arr){
        if(root==nullptr){
            return ;
        }
        arr.push_back(root->val);
        toArr(root->left,arr);
        toArr(root->right,arr);
    }

    void flatten(TreeNode* root) {
        vector<int>arr;
        toArr(root,arr);

        TreeNode* temp=root;
        for(int i=1;i<arr.size();i++){
            temp->right=new TreeNode(arr[i]);
            temp->left=nullptr;
            temp=temp->right;
        }

    }
};