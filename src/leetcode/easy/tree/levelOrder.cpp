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

class Solution {
 public:
     vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> res;
         if(root == nullptr)
            return res;
         queue<TreeNode*> q;
         q.push(root);
         while(!q.empty()){
             int numSize = q.size();
             vector<int> levelRes;
             for(int i=0;i<numSize;i++){
                 TreeNode* cur = q.front();
                 q.pop();
                 levelRes.push_back(cur->val);
                 if(cur->left != nullptr)
                     q.push(cur->left);
                 if(cur->right != nullptr)
                     q.push(cur->right);
             }   
             res.push_back(levelRes);
         }   
         return res;      
     }   
 };