#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int count = 0,n=nums.size();
		for (int i = 1; i < n; i++) {
			if (nums[i] == nums[i - 1])
				count++;
			else
				nums[i - count] = nums[i];
		}
		return n - count;
	}
};

int main(){
   Solution solution;
   vector<int> nums{0,0,1,1,1,2,2,3,3,4};
   cout << solution.removeDuplicates(nums) << endl;
   return 0;
}