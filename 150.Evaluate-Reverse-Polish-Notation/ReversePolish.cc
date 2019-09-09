#include <iostream>
#include <stack>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto& s : tokens) {
            if (s == "+" || s == "-" || s == "/" || s == "*") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();

                if (s == "+") {
                    nums.push(b + a);
                } else if (s == "-") {
                    nums.push(b - a);
                } else if (s == "*") {
                    nums.push(b * a);
                } else if (s == "/") {
                    nums.push(b / a);
                }
            } else {
                nums.push(std::atoi(s.c_str()));
            }
        }
        return nums.top();
    }
};

int main() {
    Solution solution;
    vector<string> tokens{"10", "6", "9",  "3", "+", "-11", "*",
                          "/",  "*", "17", "+", "5", "+"};
    cout << solution.evalRPN(tokens) << endl;
    return 0;
}