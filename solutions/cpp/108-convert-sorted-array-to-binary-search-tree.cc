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
  TreeNode *generate(vector<int> &nums, int low, int high) {
    if (low > high)
      return NULL;
    int mid = (low + high + 1) / 2;

    TreeNode *node = new TreeNode(nums[mid]);
    node->left = generate(nums, low, mid - 1);
    node->right = generate(nums, mid + 1, high);

    return node;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return generate(nums, 0, nums.size() - 1);
  }
};

void printTree(TreeNode *node) {
  if (node == NULL)
    return;

  cout << node->val << ' ';
  printTree(node->left);
  printTree(node->right);
}

int main() {
  vector<int> nums = {-3, 0, 4, 7, 8, 11, 12};
  TreeNode *result = Solution().sortedArrayToBST(nums);
  printTree(result);
  return 0;
}
