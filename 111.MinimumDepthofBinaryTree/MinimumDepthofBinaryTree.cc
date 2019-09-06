#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int i = 0;

        while (!que.empty()) {
            ++i;
            int k = que.size();
            for (int j = 0; j < k; ++j) {
                TreeNode* pNode = que.front();
                que.pop();
                if (pNode->left) que.push(pNode->left);
                if (pNode->right) que.push(pNode->right);
                if (pNode->left == nullptr && pNode->right == nullptr) {
                    return i;
                }
            }
        }
        return i;//不会运行到这,不加编译器会报错
    }
};

int main() {
    Solution solution;

    return 0;
}