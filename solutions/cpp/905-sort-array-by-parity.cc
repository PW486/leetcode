#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &A) {
    vector<int> even;
    vector<int> odd;

    for (int i : A) {
      if (i % 2 == 0) {
        even.push_back(i);
      } else {
        odd.push_back(i);
      }
    }
    even.insert(even.end(), odd.begin(), odd.end());

    return even;
  }
};

int main() {
  vector<int> A = {3, 1, 2, 4};
  vector<int> result = Solution().sortArrayByParity(A);

  for (auto i : result) {
    cout << i << endl;
  }

  return 0;
}
