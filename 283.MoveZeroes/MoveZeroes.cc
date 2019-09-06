#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != k)
                    std::swap(nums[k++], nums[i]);
                else
                    ++k;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}