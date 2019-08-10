#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::endl;
using std::stack;
using std::string;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> stk;
        for (const char c : s) {
            switch (c) {
                case '(':
                    stk.push(')');
                    break;
                case '{':
                    stk.push('}');
                    break;
                case '[':
                    stk.push(']');
                    break;
                default:
                    if (stk.size() == 0 || c != stk.top()) {
                        return false;
                    } else {
                        stk.pop();
                    }
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution solution;
    string s("()[]{}");
    cout << solution.isValid(s) << endl;
    return 0;
}
