#include <algorithm>
#include <iostream>
#include <string>
using std::count;
using std::cout;
using std::endl;
using std::string;

class Solution {
   public:
    string reverseVowels(string s) {
        char vowels[11] = {"aeiouAEIOU"};
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !count(vowels, vowels + 11, s[l])) {
                ++l;
            }
            while (l < r && !count(vowels, vowels + 11, s[r])) {
                --r;
            }
            std::swap(s[l], s[r]);
            ++l;
            --r;
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s("aU");
    cout << solution.reverseVowels(s) << endl;
    return 0;
}