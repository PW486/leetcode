#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
  set<char> jewels;
  int numJewelsInStones(string J, string S) {
    for (char C : J) {
      jewels.insert(C);
    }

    int count = 0;
    for (char C : S) {
      auto jewel = jewels.find(C);
      if (jewel != jewels.end()) {
        count++;
      }
    }

    return count;
  }
};

int main() {
  cout << Solution().numJewelsInStones("aA", "aAAbbbb") << endl;
  cout << Solution().numJewelsInStones("z", "ZZ") << endl;

  return 0;
}
