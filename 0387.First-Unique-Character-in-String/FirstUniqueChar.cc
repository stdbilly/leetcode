#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
   public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;

        int freq[256] = {0};
        for (auto& c : s) {
            ++freq[c];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i]] == 1) return i;
        }
        return -1;
    }
};

// ====================测试代码====================
void Test(string str, int expected) {
    Solution solution;
    if (solution.firstUniqChar(str) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[]) {
    // 常规输入测试，存在只出现一次的字符
    Test("google", 4);

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", -1);

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 0);

    // 鲁棒性测试，输入空串
    Test("", -1);

    return 0;
}