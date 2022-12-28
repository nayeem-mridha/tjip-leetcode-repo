class Solution {
public:
    vector<TreeNode*> dupSubtrees; 
    unordered_map<string, int> hashes;

    string generateHash(TreeNode* root) {
        if (root == NULL) return "#";
        string left = generateHash(root->left);
        string right = generateHash(root->right);
        string curr = to_string(root -> val) + "," + left + "," + right;
        if (hashes.count(curr) && hashes[curr] == 1) {
            dupSubtrees.push_back(root);
        }
        hashes[curr]++;
        return curr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dupSubtrees.clear();
        hashes.clear();
        generateHash(root);
        return dupSubtrees;
    }
};
