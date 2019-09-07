#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string minWindow(string s, string t) {
        int tFerq[256] = {0};
        for (auto &c : t)
        {
            ++tFerq[c];   
        }
        int sFreq[256] = {0};
        int sCnt = 0;
        int minLen = s.size() +1;
        int startIdx = -1;
        int l =0, r = -1;
        while (l < s.size())
        {
            if(r + 1 < s.size() && sCnt < t.size()) {
                ++sFreq[s[r + 1]];
                if(sFreq[s[r+1]] <= tFerq[s[r+1]]) //只统计t中含有的字母,并且只统计一次
                    ++sCnt;
                ++r;
            } else { 
                if(sCnt == t.size() && r - l +1 < minLen) { //此时窗口中含有所有t的字母
                    minLen = r - l +1;
                    startIdx = l;
                }

                --sFreq[s[l]];
                if(sFreq[s[l]] < tFerq[s[l]]) //只统计t中含有的字母
                    --sCnt;
                ++l;
            }
        }
        if(startIdx != -1) {
            return s.substr(startIdx, minLen);
        }
        return "";
    }
};

int main(){
   Solution solution;
   string s("ADOBECODEBANC");
   string t("ABC");
   cout << solution.minWindow(s, t) << endl;
   return 0;
}