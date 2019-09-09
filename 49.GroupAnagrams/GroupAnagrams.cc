#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> hashTable;
        for (const string &s : strs) {
            string key(s);
            std::sort(key.begin(), key.end());
            hashTable[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &item : hashTable) {
            res.push_back(item.second);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = solution.groupAnagrams(strs);
    for (auto &v : res) {
        for (const string &s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}