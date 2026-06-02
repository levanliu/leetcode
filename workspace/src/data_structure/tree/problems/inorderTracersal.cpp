#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTracersal(TreeNode *root)
    {
        typedef pair<int, TreeNode *> PII;
        vector<int> res;
        if (root == nullptr)
            return res;
        int n = 110;
        PII stk[n];
        int top = -1;
        stk[++top] = {0, root};
        while (top != -1)
        {
            PII cur = stk[top--];
            int color = cur.first;
            TreeNode *curNode = cur.second;
            if (color == 1)
            {
                res.push_back(curNode->val);
            }
            else
            {
                if (curNode->right != nullptr)
                    stk[++top] = {0, curNode->right};
                stk[++top] = {1, curNode};
                if (curNode->left != nullptr)
                    stk[++top] = {0, curNode->left};
            }
        }
        return res;
    }
};
