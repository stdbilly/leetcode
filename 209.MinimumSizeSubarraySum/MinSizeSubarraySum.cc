#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1;  // nums[l...r]为滑动窗口
        int sum = 0;
        int res = nums.size() + 1;
        while (l < nums.size()) {
            if (r + 1 < nums.size() && sum < s) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }
            if(sum >= s)
                res = std::min(res, r - l + 1);
        }
        
        if (res == nums.size() + 1) {
            return 0;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2, 3, 1, 2, 4, 3};
    cout << solution.minSubArrayLen(7, nums) << endl;
    return 0;
}