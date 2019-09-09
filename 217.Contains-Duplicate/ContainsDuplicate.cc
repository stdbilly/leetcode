#include <iostream>
#include <unordered_set>
#include <vector>
using std::cout;
using std::endl;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> record;
        for (int i = 0; i < nums.size(); ++i) {
            if (record.count(nums[i])) {
                return true;
            } else {
                record.insert(nums[i]);
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3, 1};
    cout << solution.containsDuplicate(nums) << endl;
    return 0;
}