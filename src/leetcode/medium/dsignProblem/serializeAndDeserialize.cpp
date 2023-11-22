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

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    TreeNode *deserializeHelper(queue<string> &dataQueue)
    {
        string q = dataQueue.front();
        dataQueue.pop();
        if (q == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(q));
        root->left = deserializeHelper(dataQueue);
        root->right = deserializeHelper(dataQueue);
        return root;
    }
    TreeNode *deserialize(string data)
    {
        queue<string> dataQueue;
        for (int i = 0; i < data.size();)
        {
            if (data[i] == ',')
            {
                i++;
            }
            int k = i;
            while (data[i] != ',' && i < data.size())
                i++;
            dataQueue.push(data.substr(k, i - k));
        }

        /**
         * java solution: by split api.
         *  Queue<String> q = new LinkedList<String>(Arrays.asList(data.split(",")));
         * 
        */

        return deserializeHelper(dataQueue);
    }
};
