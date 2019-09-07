#include <algorithm>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::pair;
using std::string;

class Solution {
   public:
    string frequencySort(string s) {
        pair<int, char> freq[256];
        for (int i = 0; i < 256; ++i) {
            freq[i].first = 0;
            freq[i].second = i;
        }
        for (int i = 0; i < s.size(); ++i) {
            ++freq[s[i]].first;
        }

        std::sort(freq, freq + 256, std::greater<pair<int, char>>());

        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            while (!freq[index].first) {
                ++index;
            }
            s[i] = freq[index].second;
            --freq[index].first;
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s("tree");
    cout << solution.frequencySort(s) << endl;
    return 0;
}