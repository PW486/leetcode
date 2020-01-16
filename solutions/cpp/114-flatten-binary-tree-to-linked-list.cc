#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == NULL)
      return;

    if (root->left != NULL) {
      flatten(root->left);

      TreeNode *right = root->right;
      root->right = root->left;
      root->left = NULL;

      TreeNode *leaf = root->right;
      while (leaf != NULL && leaf->right != NULL) {
        leaf = leaf->right;
      }
      leaf->right = right;
    }

    flatten(root->right);
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  Solution().flatten(root);
  while (root != NULL) {
    cout << root->val << endl;
    root = root->right;
  }
  return 0;
}
