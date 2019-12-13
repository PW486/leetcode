#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &A) {
    vector<int> result(A.size());

    int even = 0;
    int odd = 1;

    for (int i : A) {
      if (i % 2 == 0) {
        result[even] = i;
        even += 2;
      } else {
        result[odd] = i;
        odd += 2;
      }
    }

    return result;
  }
};

int main() {
  vector<int> A = {4, 2, 5, 7};
  vector<int> result = Solution().sortArrayByParityII(A);

  for (auto i : result) {
    cout << i << endl;
  }

  return 0;
}
