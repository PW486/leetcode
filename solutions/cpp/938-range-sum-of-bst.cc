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
  int rangeSumBST(TreeNode *root, int L, int R) {
    int sum = 0;

    if (root != NULL) {
      if (root->val >= L && root->val <= R)
        sum = root->val;
      if (root->val > L)
        sum += rangeSumBST(root->left, L, R);
      if (root->val < R)
        sum += rangeSumBST(root->right, L, R);
    }

    return sum;
  }
};
