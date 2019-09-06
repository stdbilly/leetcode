#include <iostream>
#include <vector>
#include <cassert>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    void reverseString(vector<char>& s) {
        if(s.empty()) return;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                std::swap(s[l], s[r]);
            }
            ++l;
            --r;
        }
    }
};

int main() {
    Solution solution;
    vector<char> s{'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(s);
    for (auto& c : s) {
        cout << c;
    }
    cout << endl;
    return 0;
}