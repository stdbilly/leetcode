#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                return {i +1, j+1};
            } else if (numbers[i] + numbers[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        throw std::invalid_argument("no solution");
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = solution.twoSum(nums, 9);
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}