#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> count;
    for (int i = 0; i < tasks.size(); i++) {
      count[tasks[i]]++;
    }

    int result = 0;
    while (true) {
      int localCnt = 0;
      bool isLast = true;

      for (auto it = count.begin(); it != count.end(); it++) {
        if (it->second > 0) {
          it->second--;
          localCnt++;

          if (it->second != 0) {
            isLast = false;
          }
        }
      }

      if (isLast) {
        result += localCnt;
        break;
      }

      result += n + 1;
    }

    return max(result, (int)tasks.size());
  }
};

int main() {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  cout << Solution().leastInterval(tasks, 2) << endl;
  return 0;
}
