#include <algorithm>
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
public:
  map<int, int> levelMap;
  using pair_type = decltype(levelMap)::value_type;

  int maxLevelSum(TreeNode *root) {
    levelSum(root, 1);
    auto result = max_element(levelMap.begin(), levelMap.end(),
                              [](const pair_type &p1, const pair_type &p2) {
                                return p1.second < p2.second;
                              });

    return result->first;
  }

  void levelSum(TreeNode *node, int level) {
    if (node != NULL) {
      levelMap[level] += node->val;
      levelSum(node->left, level + 1);
      levelSum(node->right, level + 1);
    }
  }
};
