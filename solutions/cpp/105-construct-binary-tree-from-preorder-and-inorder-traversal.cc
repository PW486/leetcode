#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int idx = 0, size = inorder.size();
    if (size < 1)
      return NULL;

    TreeNode *node = new TreeNode(preorder[0]);
    for (; idx < size; ++idx) {
      if (node->val == inorder[idx])
        break;
    }

    if (idx != 0) {
      vector<int> preleft(preorder.begin() + 1, preorder.begin() + idx + 1);
      vector<int> inleft(inorder.begin(), inorder.begin() + idx);
      node->left = buildTree(preleft, inleft);
    }

    if (idx < size - 1) {
      vector<int> preright(preorder.begin() + idx + 1, preorder.end());
      vector<int> inright(inorder.begin() + idx + 1, inorder.end());
      node->right = buildTree(preright, inright);
    }

    return node;
  }
};

void printTree(TreeNode *node) {
  if (node == NULL)
    return;

  printTree(node->left);
  printTree(node->right);
  cout << node->val << ' ';
}

int main() {
  vector<int> preorder = {3, 9, 10, 11, 20, 15, 7, 8};
  vector<int> inorder = {10, 9, 11, 3, 15, 20, 7, 8};

  TreeNode *result = Solution().buildTree(preorder, inorder);
  printTree(result);
  return 0;
}
