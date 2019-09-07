#include <iostream>
#include <unordered_set>
#include <vector>
using std::cout;
using std::endl;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> record(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto& i : nums2) {
            if (record.erase(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums1{4, 9, 5};
    vector<int> nums2{9, 4, 9, 8, 4};
    vector<int> res = solution.intersection(nums1, nums2);
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}