#include <iostream>
#include <stack>
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
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> ST;
    ST.push(root);

    vector<int> R;
    if (root == NULL)
      return R;
    for (TreeNode *node = ST.top(); !ST.empty(); node = ST.top(), ST.pop()) {
      if (node->left == NULL) {
        R.push_back(node->val);
      }

      if (node->right != NULL) {
        ST.push(node->right);
      }
      if (node->left != NULL) {
        ST.push(node);
        ST.push(node->left);
      }
      node->left = NULL;
      node->right = NULL;
    }

    return R;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  vector<int> result = Solution().inorderTraversal(root);
  for (auto it = result.begin(); it != result.end(); it++) {
    cout << *it << ' ';
  }

  return 0;
}
