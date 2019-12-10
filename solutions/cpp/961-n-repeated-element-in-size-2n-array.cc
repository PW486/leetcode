#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int repeatedNTimes(vector<int> &A) {
    set<int> elements;
    for (auto it = A.begin(); it != A.end(); it++) {
      if (elements.count(*it) != 0) {
        return *it;
      }
      elements.insert(*it);
    }

    return 0;
  }
};

int main() {
  vector<int> V1 = {1, 2, 3, 3};
  cout << Solution().repeatedNTimes(V1) << endl;

  vector<int> V2 = {2, 1, 2, 5, 3, 2};
  cout << Solution().repeatedNTimes(V2) << endl;

  vector<int> V3 = {5, 1, 5, 2, 5, 3, 5, 4};
  cout << Solution().repeatedNTimes(V3) << endl;

  return 0;
}
