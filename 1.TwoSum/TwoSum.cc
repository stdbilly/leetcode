#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (record.count(complement)) {
                return {record[complement], i};
            }
            record[nums[i]] = i;
        }
        throw std::invalid_argument("no solution");
    }
};

int main() {
    Solution solution;
    vector<int> nums{2, 7, 11, 15};
    vector<int> res = solution.twoSum(nums, 9);
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}