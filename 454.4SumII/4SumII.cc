#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                     vector<int>& D) {
        unordered_map<int, int> hashTable;
        for (auto& i : C) {
            for (auto& j : D) {
                ++hashTable[i + j];
            }
        }
        int res = 0;
        for (auto& i : A) {
            for (auto& j : B) {
                if (hashTable.count(-i - j)) {
                    res += hashTable[-i - j];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    cout << solution.fourSumCount(A,B,C,D) << endl;
    return 0;
}