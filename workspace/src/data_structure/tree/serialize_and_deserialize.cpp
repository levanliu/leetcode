#include <queue>
#include <string>
#include "workspace/src/data_structure/tree/tree_node.hpp"

namespace ns_tree_serialize_deserialize {

class Solution {
public:
    std::string serialize(TreeNode* root) {
        if (root == nullptr)
            return "#";
        return std::to_string(root->val) + "," + serialize(root->left) + "," +
               serialize(root->right);
    }
    TreeNode* deserializeHelper(std::queue<std::string>& dataQueue) {
        std::string q = dataQueue.front();
        dataQueue.pop();
        if (q == "#")
            return nullptr;
        TreeNode* root = new TreeNode(std::stoi(q));
        root->left = deserializeHelper(dataQueue);
        root->right = deserializeHelper(dataQueue);
        return root;
    }
    TreeNode* deserialize(std::string data) {
        std::queue<std::string> dataQueue;
        for (int i = 0; i < data.size();) {
            if (data[i] == ',') {
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

}  // namespace ns_tree_serialize_deserialize
