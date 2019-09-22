#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int maxNumberOfApples(vector<int>& arr) {
        if (arr.empty()) return 0;

        std::sort(arr.begin(), arr.end());

        int sum = 0;
        int i = 0;
        while (i < arr.size()) {
            sum += arr[i];

            if(sum > 5000) {
                break;
            }
            ++i;
        }
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> arr{900,950,800,1000,700,800};
    cout << solution.maxNumberOfApples(arr) << endl;
    return 0;
}