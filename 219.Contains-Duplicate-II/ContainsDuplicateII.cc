#include <iostream>
#include <unordered_set>
#include <vector>
using std::unordered_set;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> record;
        for (int i = 0; i < nums.size(); ++i)
        {
            if(record.count(nums[i])) {
                return true;
            }
            record.insert(nums[i]);
            //滑动窗口中有k+1个元素,才能保证两个数的最大距离为k
            if(record.size() == k+1) {
                record.erase(nums[i -k]);
            }
        }
        return false;        
    }
};

int main(){
   Solution solution;
   vector<int> nums1{1,2,3,1};
   cout << solution.containsNearbyDuplicate(nums1, 3) << endl;
   vector<int> nums2{1,2,3,1,2,3};
   cout << solution.containsNearbyDuplicate(nums2, 2) << endl;
   return 0;
}