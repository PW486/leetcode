#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    set<int> store;
    store.insert(n);

    while (n != 1) {
      int m = 0;

      while (n) {
        int digit = n % 10;
        m += digit * digit;
        n /= 10;
      }

      if (store.find(m) != store.end())
        return false;

      store.insert(m);
      n = m;
    }

    return true;
  }
};

int main() {
  cout << Solution().isHappy(486) << endl;
  return 0;
}
