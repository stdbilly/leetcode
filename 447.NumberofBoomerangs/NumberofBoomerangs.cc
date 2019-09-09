#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            //存储其他点到点i的距离出现的频次
            unordered_map<int, int> record;
            for (int j = 0; j < points.size(); ++j) {
                if (i != j) {
                    ++record[distance(points[i], points[j])];
                }
            }

            for (auto& item : record) {
                //因为要取2个点,所以有n*(n-1)种情况
                res += item.second * (item.second - 1);
            }
        }
        return res;
    }

   private:
    int distance(const vector<int>& pa, const vector<int>& pb) {
        return (pa[0] - pb[0]) * (pa[0] - pb[0]) +
               (pa[1] - pb[1]) * (pa[1] - pb[1]);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points{{0,0},{1,0},{2,0}};
    cout << solution.numberOfBoomerangs(points) << endl; 
    vector<vector<int>> p2{{1,1},{2,2},{3,3}};
    cout << solution.numberOfBoomerangs(p2) << endl;
    return 0;
}