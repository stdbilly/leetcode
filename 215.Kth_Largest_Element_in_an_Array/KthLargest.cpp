#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return findKthLargest(nums, 0, nums.size() - 1, k - 1);
    }

   private:
    int findKthLargest(vector<int>& nums, int l, int r, int k) {
        if (l == r) {
            return nums[l];
        }

        int p = partition(nums, l, r);

        if (p == k) {
            return nums[p];
        } else if (k < p) {
            return findKthLargest(nums, l, p - 1, k);
        } else {  // k >p
            return findKthLargest(nums, p + 1, r, k);
        }
    }

    int partition(vector<int>& nums, int l, int r) {
        int p = rand() % (r - l + 1) + l;
        swap(nums[l], nums[p]);

        int lt = l + 1;  // nums[l+1...lt] > nums[p]; nums[lt....i] < nums[p]
        for (int i = l + 1; i <= r; i++) {
            // nums[l]就是分割点，应为它与nums[p]交换了位置
            //[l+1, lt]之间保存的是大于nums[l]也就是分割点的数
            if (nums[i] > nums[l]) {
                swap(nums[i], nums[lt++]);
            }
        }
        //将最后一个大于nums[l]的数与nums[l]交换
        swap(nums[l], nums[lt - 1]);
        return lt - 1;  //返回分割点
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << solution.findKthLargest(nums1, 2) << endl;
    return 0;
}
