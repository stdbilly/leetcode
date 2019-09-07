#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str);
        if (pattern.size() != words.size()) {
            return false;
        }
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        int i1 = -1, i2 = -1;
        for (int i = 0; i < pattern.size(); ++i) {
            if (m1.count(pattern[i])) i1 = m1[pattern[i]];
            if (m2.count(words[i])) i2 = m2[words[i]];

            if (i1 != i2) return false;

            m1[pattern[i]] = i;
            m2[words[i]] = i;
        }
        return true;
    }

   private:
    vector<string> split(const string& s) {
        vector<string> res;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            res.push_back(word);
        }
        return res;
    }
};

int main() {
    Solution solution;
    string pattern = "abba", str = "dog cat cat dog";
    cout << solution.wordPattern(pattern, str) << endl;
    return 0;
}