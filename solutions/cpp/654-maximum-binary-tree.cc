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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.size() == 0)
      return NULL;

    int maxNum = 0, maxIdx = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (maxNum < nums[i]) {
        maxNum = nums[i];
        maxIdx = i;
      }
    }

    TreeNode *node = new TreeNode(maxNum);
    vector<int> left(nums.begin(), nums.begin() + maxIdx);
    node->left = constructMaximumBinaryTree(left);
    vector<int> right(nums.begin() + maxIdx + 1, nums.end());
    node->right = constructMaximumBinaryTree(right);

    return node;
  }
};
