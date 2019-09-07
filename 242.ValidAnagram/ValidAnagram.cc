#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> sFreq(26, 0);
        vector<int> tFreq(26, 0);
        for (auto &c : s) {
            ++sFreq[c - 'a'];
        }
        for (auto &c : t) {
            ++tFreq[c - 'a'];
        }
        if (sFreq == tFreq) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution solution;
    string s = "anagram", t = "nagaram";
    cout << solution.isAnagram(s,t) << endl;
    return 0;
}