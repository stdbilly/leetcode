#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        vector<int> res;
        vector<int> freq_s(26, 0);
        vector<int> freq_q(26, 0);
        for (char c : p) {
            ++freq_q[c - 'a'];
        }
        for (int i = 0; i < sLen; ++i) {
            if (i >= pLen) {  //滑动窗口大小为pLen
                --freq_s[s[i - pLen] - 'a'];
            }
            ++freq_s[s[i] - 'a'];
            if (freq_q == freq_s) {
                res.push_back(i - pLen + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s("cbaebabacd");
    string p("abc");
    vector<int> res = solution.findAnagrams(s, p);
    for (auto &i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}