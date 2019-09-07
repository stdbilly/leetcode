#include <math.h>
#include <iostream>
#include <unordered_set>
using std::cout;
using std::endl;
using std::unordered_set;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> res;
        int sum = 0;
        while (n != 1)
        {
            while (n)
            {
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
            sum = 0;
            if(res.count(n)) {
                return false;
            } else {
                res.insert(n);
            }
        }
        return true;   
    }
};

int main(){
   Solution solution;
   cout << solution.isHappy(19) << endl;
   return 0;
}