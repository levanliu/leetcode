#include <bits/stdc++.h>
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

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root,root);
    }

    bool isSymmetricHelper(TreeNode* root1,TreeNode* root2){
        if( root1 == nullptr || root2 == nullptr  )
            return root1 == root2;
        
        if(root1->val != root2->val)
            return false;
        
        return isSymmetricHelper(root1->left,root2->right) &&
                isSymmetricHelper(root2->left,root1->right);
    }
};