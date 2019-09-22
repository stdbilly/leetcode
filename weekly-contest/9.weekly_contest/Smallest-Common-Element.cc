#include <iostream>
#include <vector>
#include <set>
#include <queue>
using std::set;
using std::priority_queue;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        set<int> record(mat[0].begin(), mat[0].end());
        priority_queue<int> res;

        for (int i = 1; i < mat.size(); ++i)
        {
            /* code */
        }
        
        
    }

private:
    set<int> recordLast;
    set<int> recordCur;
};

int main(){
   Solution solution;
   
   return 0;
}