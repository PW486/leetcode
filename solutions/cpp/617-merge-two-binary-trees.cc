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
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 == NULL && t2 == NULL)
      return NULL;

    int sum = 0;
    TreeNode *left;
    TreeNode *right;

    if (t1 != NULL && t2 != NULL) {
      sum = t1->val + t2->val;
      left = mergeTrees(t1->left, t2->left);
      right = mergeTrees(t1->right, t2->right);
    } else if (t1 != NULL) {
      sum = t1->val;
      left = mergeTrees(t1->left, NULL);
      right = mergeTrees(t1->right, NULL);
    } else if (t2 != NULL) {
      sum = t2->val;
      left = mergeTrees(NULL, t2->left);
      right = mergeTrees(NULL, t2->right);
    }

    TreeNode *mergeNode = new TreeNode(sum);
    mergeNode->left = left;
    mergeNode->right = right;

    return mergeNode;
  }
};

void printTree(TreeNode *node) {
  if (node == NULL)
    return;

  printTree(node->left);
  cout << node->val << ' ';
  printTree(node->right);
}

int main() {
  TreeNode *t1 = new TreeNode(1);
  t1->left = new TreeNode(3);
  t1->right = new TreeNode(2);
  t1->left->left = new TreeNode(5);

  TreeNode *t2 = new TreeNode(2);
  t2->left = new TreeNode(1);
  t2->right = new TreeNode(3);
  t2->left->right = new TreeNode(4);
  t2->right->right = new TreeNode(7);

  TreeNode *r = Solution().mergeTrees(t1, t2);
  printTree(r);

  return 0;
}
