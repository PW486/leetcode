#include <iostream>

using namespace std;

class Solution {
public:
  bool divisorGame(int N) { return N % 2 == 0; }
};

int main() {
  cout << Solution().divisorGame(486) << endl;
  return 0;
}
