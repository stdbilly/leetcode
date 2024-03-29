#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] == target) {
                return mid;
            }

            if (target < nums[mid]) {
                if (nums[l] <= nums[r] || nums[mid] < nums[l])
                    r = mid - 1;
                else if (target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (nums[l] <= nums[r] || nums[mid] > nums[l])
                    l = mid + 1;
                else if (target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << Solution().search(nums1, target1) << endl;
    // 4

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << Solution().search(nums2, target2) << endl;
    // -1

    vector<int> nums3 = {1, 3};
    int target3 = 3;
    cout << Solution().search(nums3, target3) << endl;
    // 1

    vector<int> nums4 = {5, 1, 3};
    int target4 = 5;
    cout << Solution().search(nums4, target4) << endl;
    // 0

    vector<int> nums5 = {4, 5, 6, 7, 8, 1, 2, 3};
    int target5 = 8;
    cout << Solution().search(nums5, target5) << endl;
    // 4
    return 0;
}