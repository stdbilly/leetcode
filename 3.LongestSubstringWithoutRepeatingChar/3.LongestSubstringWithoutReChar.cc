#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = -1;  //滑动窗口为[l...r]
        int res = 0;
        char freq[256] = {0};
        while (l < s.size()) {
            if (r + 1 < s.size() && freq[s[r + 1]] == 0) {
                ++freq[s[++r]];
            } else {  //右边界无法扩展了,扩展左边界
                --freq[s[l++]];
            }
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s("abcabcbb");
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}