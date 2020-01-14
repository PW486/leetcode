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
private:
  vector<int> vec;

public:
  int kthSmallest(TreeNode *root, int k) {
    insertToVec(root);
    return vec[k - 1];
  }

  void insertToVec(TreeNode *node) {
    if (node == NULL)
      return;
    insertToVec(node->left);
    vec.push_back(node->val);
    insertToVec(node->right);
  }
};

int main() {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);

  cout << Solution().kthSmallest(root, 3) << endl;
  return 0;
}
