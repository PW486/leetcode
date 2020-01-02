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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    traversal(result, root, 0);

    return result;
  }

  void traversal(vector<vector<int>> &result, TreeNode *node, int level) {
    if (node != NULL) {
      if (result.size() <= level) {
        result.push_back({});
      }
      result[level].push_back(node->val);
      traversal(result, node->left, level + 1);
      traversal(result, node->right, level + 1);
    }
  }
};

int main() {
  TreeNode *node = new TreeNode(3);
  node->left = new TreeNode(9);
  node->right = new TreeNode(20);
  node->right->left = new TreeNode(15);
  node->right->right = new TreeNode(7);

  vector<vector<int>> result = Solution().levelOrder(node);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
