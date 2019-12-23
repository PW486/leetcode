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
  int maxNum;

public:
  int maxDepth(TreeNode *root) {
    if (root == NULL)
      return 0;
    maxNum = 1;

    childDepth(root->left, 2);
    childDepth(root->right, 2);

    return maxNum;
  }
  void childDepth(TreeNode *node, int depth) {
    if (node == NULL) {
      if (depth - 1 > maxNum) {
        maxNum = depth - 1;
      }

      return;
    }

    childDepth(node->left, depth + 1);
    childDepth(node->right, depth + 1);
  }
};

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  cout << Solution().maxDepth(root) << endl;
  return 0;
}
