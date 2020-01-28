#include <iostream>
#include <vector>

using namespace std;

class Solution {
  vector<int> nums;

public:
  Solution(vector<int> nums) { this->nums = nums; }

  vector<int> reset() { return nums; }

  vector<int> shuffle() {
    vector<int> result(nums);

    for (int i = 0; i < result.size(); i++) {
      int pos = rand() % (result.size() - i);
      swap(result[i + pos], result[i]);
    }

    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution *obj = new Solution(nums);

  vector<int> result_1 = obj->shuffle();
  for (auto e : result_1) {
    cout << e << ' ';
  }
  cout << endl;

  vector<int> result_2 = obj->reset();
  for (auto e : result_2) {
    cout << e << ' ';
  }
  cout << endl;

  return 0;
}
