#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int maxDiameter;

  void recursive(TreeNode *node) {
    if (node == NULL)
      return;
    int diameter = findDepth(node->left, 0) + findDepth(node->right, 0);
    maxDiameter = max(maxDiameter, diameter);

    recursive(node->left);
    recursive(node->right);
  }

  int findDepth(TreeNode *node, int level) {
    if (node == NULL)
      return level;
    return max(findDepth(node->left, level + 1),
               findDepth(node->right, level + 1));
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == NULL)
      return 0;
    maxDiameter = findDepth(root->left, 0) + findDepth(root->right, 0);

    recursive(root->left);
    recursive(root->right);

    return maxDiameter;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  cout << Solution().diameterOfBinaryTree(root) << endl;
  return 0;
}
