#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
   public:
    bool isPalindrome(string s) {
        int l = nextAlnum(s, 0);
        int r = preAlnum(s, s.size() - 1);
        while (l <= r) {
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l = nextAlnum(s, l + 1);
            r = preAlnum(s, r - 1);
        }
        return true;
    }

   private:
    int nextAlnum(const string& s, int idx) {
        for (int i = idx; i < s.size(); ++i) {
            if (isalnum(s[i])) return i;
        }
        return s.size();
    }

    int preAlnum(const string& s, int idx) {
        for (int i = idx; i >= 0; --i) {
            if (isalnum(s[i])) return i;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(s) << endl;
    return 0;
}