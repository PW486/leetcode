#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<vector<int>, vector<string>> store;

    for (auto it = strs.begin(); it != strs.end(); it++) {
      vector<int> alphabet(26);
      for (char c : *it) {
        alphabet[c - 'a']++;
      }
      store[alphabet].push_back(*it);
    }

    vector<vector<string>> result;

    for (auto map_it = store.begin(); map_it != store.end(); map_it++) {
      vector<string> group;
      for (auto vec_it = map_it->second.begin(); vec_it != map_it->second.end();
           vec_it++) {
        group.push_back(*vec_it);
      }
      result.push_back(group);
    }

    return result;
  }
};

int main() {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result = Solution().groupAnagrams(strs);

  for (auto it_1 = result.begin(); it_1 != result.end(); it_1++) {
    for (auto it_2 = (*it_1).begin(); it_2 != (*it_1).end(); it_2++) {
      cout << *it_2 << ' ';
    }
    cout << endl;
  }

  return 0;
}
