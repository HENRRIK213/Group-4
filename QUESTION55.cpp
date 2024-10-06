#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(NULL), right(NULL) {}
    
    // Constructor with value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function for inorder traversal
    void inOrder(TreeNode* root, vector<int> &ans) {
        if (!root) return; // Base case: if the node is null, return
        inOrder(root->left, ans); // Traverse left subtree
        ans.push_back(root->val);  // Visit node
        inOrder(root->right, ans); // Traverse right subtree
    }

    // Function to perform inorder traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;          // Vector to hold the traversal result
        inOrder(root, ans);      // Start the traversal
        return ans;              // Return the result
    }
};

// Function to create a sample tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);                  // Create root
    root->left = new TreeNode(2);                       // Left child
    root->right = new TreeNode(3);                      // Right child
    root->left->left = new TreeNode(4);                 // Left-Left child
    return root;                                         // Return the created tree
}

int main() {
    // Create a sample tree
    TreeNode* root = createSampleTree();

    // Create a Solution object
    Solution solution;

    // Get the inorder traversal
    vector<int> result = solution.inorderTraversal(root);

    // Output the result using a traditional for loop
    cout << "Inorder Traversal: ";
    for (size_t i = 0; i < result.size(); ++i) { // Traditional for loop
        cout << result[i] << " ";   // Print each value
    }
    cout << endl;

    // Clean up memory
    delete root->left->left; // Node with value 4
    delete root->left;       // Node with value 2
    delete root->right;      // Node with value 3
    delete root;             // Node with value 1

    return 0;                // Exit the program
}
