#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  map<pair<TreeNode *, bool>, int> memo;

  int sum(TreeNode *node, bool isSelect) {
    if (node == NULL)
      return 0;

    pair<TreeNode *, bool> p(node, isSelect);
    if (memo[p])
      return memo[p];

    int result = 0;
    if (isSelect) {
      result += node->val;
      result += sum(node->left, false);
      result += sum(node->right, false);
    } else {
      result += max(sum(node->left, true), sum(node->left, false));
      result += max(sum(node->right, true), sum(node->right, false));
    }

    memo[p] = result;
    return result;
  }

public:
  int rob(TreeNode *root) { return max(sum(root, true), sum(root, false)); }
};

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(1);

  cout << Solution().rob(root) << endl;
  return 0;
}
