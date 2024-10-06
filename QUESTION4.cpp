#include <iostream>
#include <climits> // For INT_MIN
#include <algorithm> // For max function

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {} // Use NULL instead of nullptr
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Use NULL instead of nullptr
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPath(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;

        int lh = std::max(0, maxPath(root->left, maxi)); // max path sum of left subtree
        int rh = std::max(0, maxPath(root->right, maxi)); // max path sum of right subtree
        maxi = std::max(maxi, lh + rh + root->val); // update maximum path sum

        return root->val + std::max(lh, rh); // return the max path sum extending to parent
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};

// Function to create a sample tree for testing: 
// Example tree:
//       1
//      / \
//     2   3
//    /
//   4
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution solution;
    int result = solution.maxPathSum(root);
    std::cout << "Maximum Path Sum: " << result << std::endl;

    // Clean up memory
    delete root->left->left; // Node with value 4
    delete root->left;       // Node with value 2
    delete root->right;      // Node with value 3
    delete root;             // Node with value 1

    return 0;
}
