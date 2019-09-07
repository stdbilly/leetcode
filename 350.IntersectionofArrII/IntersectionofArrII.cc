#include <iostream>
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> record;
        for (auto &i : nums1)
        {
            ++record[i];   
        }
        vector<int> res;
        for (auto &i : nums2)
        {
            if(record.count(i) && record[i] > 0) {
                res.push_back(i);
                --record[i];
            }   
        }
        return res;
    }
};

int main(){
   Solution solution;
    vector<int> nums1{4, 9, 5};
    vector<int> nums2{9, 4, 9, 8, 4};
    vector<int> res = solution.intersect(nums1, nums2);
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
   return 0;
}