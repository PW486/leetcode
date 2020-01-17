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
  int count;

  void selectNode(TreeNode *node, int sum, bool select) {
    if (node == NULL)
      return;
    if (select) {
      sum -= node->val;
      if (sum == 0)
        count++;
    }

    if (!select) {
      selectNode(node->left, sum, false);
      selectNode(node->right, sum, false);
    }
    selectNode(node->left, sum, true);
    selectNode(node->right, sum, true);
  }

public:
  int pathSum(TreeNode *root, int sum) {
    if (root == NULL)
      return 0;
    selectNode(root, sum, false);
    selectNode(root, sum, true);

    return count;
  }
};

int main() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(-3);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(3);
  root->left->left->right = new TreeNode(-2);
  root->left->right = new TreeNode(2);
  root->left->right->right = new TreeNode(1);
  root->right->right = new TreeNode(11);

  cout << Solution().pathSum(root, 8) << endl;
  return 0;
}
