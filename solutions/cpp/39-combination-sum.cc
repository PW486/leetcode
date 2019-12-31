#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> combination;
    combinationSum(candidates, target, res, combination, 0);
    return res;
  }

private:
  void combinationSum(vector<int> &candidates, int target,
                      vector<vector<int>> &res, vector<int> &combination,
                      int begin) {
    if (!target) {
      res.push_back(combination);
      return;
    }
    for (int i = begin; i != candidates.size() && target >= candidates[i];
         ++i) {
      combination.push_back(candidates[i]);
      combinationSum(candidates, target - candidates[i], res, combination, i);
      combination.pop_back();
    }
  }
};

class Solution_TimeLimit {
public:
  map<vector<int>, bool> store;

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    for (int i = 0; i < candidates.size(); i++) {
      vector<int> count(candidates.size());
      count[i]++;
      combinationSum(result, target, candidates, count, candidates[i]);
    }

    return result;
  }

  void combinationSum(vector<vector<int>> &result, int target,
                      vector<int> &candidates, vector<int> &count, int sum) {
    if (store[count])
      return;

    if (sum > target) {
      return;
    } else if (sum == target) {
      vector<int> newCase;
      for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < count[i]; j++) {
          newCase.push_back(candidates[i]);
        }
      }
      result.push_back(newCase);
      store[count] = true;
    } else if (sum < target) {
      for (int i = 0; i < candidates.size(); i++) {
        vector<int> newCount(count.begin(), count.end());
        newCount[i]++;
        combinationSum(result, target, candidates, newCount,
                       sum + candidates[i]);
      }
    }
  }
};

int main() {
  vector<int> candidates = {2, 3, 5};
  int target = 8;

  vector<vector<int>> result = Solution().combinationSum(candidates, target);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
