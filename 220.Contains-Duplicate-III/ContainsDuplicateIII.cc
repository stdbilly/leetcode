#include <iostream>
#include <set>
#include <vector>
using std::cout;
using std::endl;
using std::set;
using std::vector;

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> record;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = record.lower_bound((long)nums[i] - (long)t);
            if (iter!= record.end() && *iter <= (long)nums[i] + (long)t) {
                return true;
            }
            record.insert(nums[i]);
            //滑动窗口中有k+1个元素,才能保证两个数的最大距离为k
            if (record.size() == k + 1) {
                record.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3,1};
    cout << solution.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;
    return 0;
}