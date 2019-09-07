#include <cstring>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        int map[256];
        memset(map, -1, sizeof(map));
        bool mapped[256];
        memset(mapped, false, sizeof(mapped));
        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i]] == -1) {
                if (mapped[t[i]]) {
                    return false;
                }
                map[s[i]] = t[i];
                mapped[t[i]] = true;
            } else if (map[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "paper", t = "title";
    cout << solution.isIsomorphic(s,t) << endl;
    return 0;
}