/**
 * Definition for a binary tree Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
    }
}

class SD{
    public:

    vector<string>serialize(Node* root){
        vector<string>list;
        helper(root,list);
        return list;
    }

    void helper(TreeNode* root,vector<string>&list){
        if(root==nullptr){
            list.push_back("null");
        }
        list.push_back(to_string(root->val));
        helper(root->left,list);
        helper(root->right,list);
    }

    Node* deserealize(vector<string>&list){
        vector<string>reversed_list(list);
        reverse(reversed_list.begin(),reversed_list.end());
        return helper2(reversed_list);
    }

    Node* helper2(vector<string>&list){
        string val=list.back();
        list.pop_back();

        if(val=="null"){
            return nullptr;
        }
        Node* node=new Node(stoi(val));
        node->right=helper2(list);
        node->left=helper2(list);

        return node;
    }
}



int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    string s = serialize(root);
    deserialize(s);
}