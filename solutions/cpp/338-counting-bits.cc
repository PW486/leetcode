#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> vec(num + 1);
    for (int i = 0; i <= num; i++) {
      vec[i] = vec[i >> 1] + i % 2;
    }

    return vec;
  }
};

int main() {
  vector<int> result = Solution().countBits(486);
  for (auto it = result.begin(); it != result.end(); it++) {
    cout << *it << ' ';
  }

  return 0;
}
