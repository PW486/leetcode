#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), [](vector<int> p1, vector<int> p2) {
      return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    });
    vector<vector<int>> sol;
    for (auto person : people) {
      sol.insert(sol.begin() + person[1], person);
    }
    return sol;
  }

  vector<vector<int>> reconstructQueue_timeLimit(vector<vector<int>> &people) {
    for (int i = 0; i < people.size(); i++) {
      int idx = 0, gteNum = 0, pos = 0;

      for (idx = 0; idx < i; idx++) {
        if (people[idx][0] >= people[i][0]) {
          gteNum++;
        }
        if (gteNum == people[i][1]) {
          pos = idx + 1;
        }
      }

      if (gteNum > people[i][1]) {
        vector<int> temp = people[i];
        for (int j = i; j > pos; j--) {
          people[j] = people[j - 1];
        }
        people[pos] = temp;
        i = pos;
        continue;
      }
      if (gteNum == people[i][1]) {
        continue;
      }

      for (idx = i + 1; idx < people.size(); idx++) {
        if (people[idx][0] >= people[i][0]) {
          gteNum++;

          if (gteNum == people[i][1]) {
            break;
          }
        }
      }

      vector<int> temp = people[i];
      for (int j = i; j < idx; j++) {
        people[j] = people[j + 1];
      }
      people[idx] = temp;
      i--;
    }

    return people;
  }
};

int main() {
  vector<vector<int>> vec = {{2, 4}, {3, 4}, {9, 0}, {0, 6}, {7, 1},
                             {6, 0}, {7, 3}, {2, 5}, {1, 1}, {8, 0}};
  Solution().reconstructQueue(vec);

  for (auto it = vec.begin(); it != vec.end(); it++) {
    cout << (*it)[0] << ' ' << (*it)[1] << endl;
  }

  return 0;
}
