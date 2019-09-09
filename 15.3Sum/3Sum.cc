#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

// using hashtalbe to store all the numsbers
// time complexity: O(n^2)
// space complexity: O(n)

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            if (target < 0) {
                break;
            }

            while (front < back) {
                int sum = nums[front] + nums[back];

                // Finding answer which start from number nums[i]
                if (sum < target)
                    ++front;

                else if (sum > target)
                    --back;

                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);

                    // Processing duplicates of number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1]) ++front;

                    // Processing duplicates of number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[2]) --back;
                }
            }

            // Processing duplicates of numsber 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> numss{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    res = solution.threeSum(numss);
    for (auto& v : res) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}