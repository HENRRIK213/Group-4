#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder; // Vector to hold the preorder traversal result
        stack<TreeNode*> stack; // Stack to hold the nodes
        if (root == NULL) // If the root is null, return an empty vector
            return preorder;
        stack.push(root); // Push the root onto the stack
        while (!stack.empty()) {
            TreeNode* curr = stack.top(); // Get the top node
            stack.pop(); // Pop the top node
            preorder.push_back(curr->val); // Store the value in the result

            // Push right child first so that left child is processed first
            if (curr->right != NULL)
                stack.push(curr->right);
            if (curr->left != NULL)
                stack.push(curr->left);
        }
        return preorder; // Return the preorder result
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

    // Get the preorder traversal
    vector<int> result = solution.preorderTraversal(root);

    // Output the result using a traditional for loop
    cout << "Preorder Traversal: ";
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
