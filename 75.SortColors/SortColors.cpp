#include <cassert>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int zero = -1;          // nums[0...zero] = 0
        int two = nums.size();  // nums[two...n-1] = 2

        for (int i = 0; i < two;) {
            if (nums[i] == 1) {
                ++i;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[--two]);
            } else {  // nums[i] == 0
                assert(nums[i] == 0);
                std::swap(nums[++zero], nums[i]);
                ++i;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution solution;
    solution.sortColors(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}