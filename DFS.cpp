#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) {
    val = value;
    left = right = nullptr;
  }
};

void DFS(TreeNode* root) {
  if (root == nullptr) {
    return; // Base case: empty tree
  }

  stack<TreeNode*> nodeStack;
  nodeStack.push(root);

  while (!nodeStack.empty()) {
    // Pop the top element from the stack
    TreeNode* current = nodeStack.top();
    nodeStack.pop();

    // Visit the current node (preorder)
    cout << current->val << " ";

    if (current->right != nullptr) {
      nodeStack.push(current->right);
    }
    if (current->left != nullptr) {
      nodeStack.push(current->left);
    }
  }
}

int main() {
  // Create a sample tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  // Perform DFS traversal (preorder by default)
  cout << "DFS traversal using stack (preorder): ";
  DFS(root);

  return 0;
}
