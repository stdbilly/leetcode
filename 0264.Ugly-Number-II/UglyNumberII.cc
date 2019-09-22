#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;

        vector<int> uglyNums(n);
        uglyNums[0] = 1;
        auto iterMultiply2 = uglyNums.begin();
        auto iterMultiply3 = uglyNums.begin();
        auto iterMultiply5 = uglyNums.begin();

        for (int i = 1; i < n; ++i) {
            int min = tripleMin(*iterMultiply2 * 2, *iterMultiply3 * 3,
                                *iterMultiply5 * 5);
            uglyNums[i] = min;

            while (*iterMultiply2 * 2 <= uglyNums[i]) {
                ++iterMultiply2;
            }
            while (*iterMultiply3 * 3 <= uglyNums[i]) {
                ++iterMultiply3;
            }
            while (*iterMultiply5 * 5 <= uglyNums[i]) {
                ++iterMultiply5;
            }
        }
        return uglyNums[n - 1];
    }

   private:
    int tripleMin(const int& a, const int& b, const int& c) {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }
};

// ====================测试代码====================
void Test(int index, int expected) {
    Solution solution;
    if (solution.nthUglyNumber(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int main(int argc, char* argv[]) {
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}