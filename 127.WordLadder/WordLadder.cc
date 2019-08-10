#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::unordered_set;
using std::vector;

// Bidirectional BFS
class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        int len = beginWord.length();
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int step = 0;
        while (!q1.empty() && !q2.empty()) {
            ++step;
            //总是扩展最小的集合
            if (q1.size() > q2.size()) {
                swap(q1, q2);
            }

            unordered_set<string> q;

            for (string w : q1) {
                for (int i = 0; i < len; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!dict.count(w)) continue;
                        dict.erase(w); //如果在字典中将其删除
                        q.insert(w);
                    }
                    w[i] = ch; //将取出的单词还原
                }
            }
            swap(q, q1); //更新q1
        }
        return 0;
    }
};

int main() {
    Solution solution;
    string beginWord("hit");
    string endWord("cog");
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    int ret = solution.ladderLength(beginWord, endWord, wordList);
    cout << ret << endl;
    return 0;
}