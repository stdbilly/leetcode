#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        size_t lhs_len = word1.size();
        size_t rhs_len = word2.size();
        int editDist[lhs_len + 1][rhs_len + 1];

        for (size_t idx = 0; idx <= lhs_len; ++idx) {
            editDist[idx][0] = idx;
        }

        for (size_t idx = 0; idx <= rhs_len; ++idx) {
            editDist[0][idx] = idx;
        }

        for (size_t dist_i = 1, lhs_idx = 0; dist_i <= lhs_len;
             ++dist_i, ++lhs_idx) {
            for (size_t dist_j = 1, rhs_idx = 0; dist_j <= rhs_len;
                 ++dist_j, ++rhs_idx) {
                if (word1[lhs_idx] == word2[rhs_idx]) {
                    editDist[dist_i][dist_j] = editDist[dist_i - 1][dist_j - 1];
                } else {
                    editDist[dist_i][dist_j] =
                        triple_min(editDist[dist_i][dist_j - 1] + 1,
                                   editDist[dist_i - 1][dist_j] + 1,
                                   editDist[dist_i - 1][dist_j - 1] + 1);
                }
            }
        }
        return editDist[lhs_len][rhs_len];
    }

    int triple_min(const int& a, const int& b, const int& c) {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }
};

int main() {
    Solution solution;
    //string word1 = "horse", word2 = "ros";
    string word1 = "intention", word2 = "execution";
    cout << solution.minDistance(word1, word2);
    return 0;
}