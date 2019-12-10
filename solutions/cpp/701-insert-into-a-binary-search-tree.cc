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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    TreeNode *node = root;

    while (node != NULL) {
      if (node->val > val) {
        if (node->left == NULL) {
          node->left = new TreeNode(val);
          break;
        }
        node = node->left;
      } else if (node->val < val) {
        if (node->right == NULL) {
          node->right = new TreeNode(val);
          break;
        }
        node = node->right;
      }
    }

    return root;
  }
};
