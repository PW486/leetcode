#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
    return nums[k - 1];
  }
};

int main() {
  vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  cout << Solution().findKthLargest(nums, 4) << endl;
  return 0;
}
