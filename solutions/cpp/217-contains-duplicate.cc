#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
private:
  set<int> S;

public:
  bool containsDuplicate(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      auto it = S.find(nums[i]);
      if (it != S.end())
        return true;
      S.insert(nums[i]);
    }
    return false;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 1};
  cout << Solution().containsDuplicate(nums) << endl;
  return 0;
}
