#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return res;
        
        used = vector<bool>(nums.size(), false);
        vector<int> permutation;
        generatePermutation(nums, 0, permutation);

        return res;
    }

   private:
    void generatePermutation(vector<int>& nums, int index,
                             vector<int>& permutation) {
        if (index == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                permutation.push_back(nums[i]);
                used[i] = true;

                generatePermutation(nums, index + 1, permutation);

                permutation.pop_back();
                used[i] = false;
            }
        }
        return;
    }

   private:
    vector<vector<int>> res;
    vector<bool> used;
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = solution.permute(nums);
    for (auto& vec : res) {
        display(vec);
    }

    return 0;
}