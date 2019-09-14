#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::endl;
using std::stack;
using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            res.push_back(cur->val);
            stk.pop();
            if (cur->right) {
                stk.push(cur->right);
            }
            if (cur->left) {
                stk.push(cur->left);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    return 0;
}