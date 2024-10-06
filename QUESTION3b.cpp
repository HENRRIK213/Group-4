#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For std::reverse

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return {}; // Return an empty vector if the root is null

        stack<TreeNode*> st; // Stack to hold the nodes
        st.push(root); // Push the root onto the stack
        vector<int> ans; // Vector to hold the postorder traversal result

        while (!st.empty()) {
            TreeNode* top = st.top(); // Get the top node
            st.pop(); // Pop the top node
            ans.push_back(top->val); // Store the value in the result

            // Push left and right children to the stack
            if (top->left) st.push(top->left);
            if (top->right) st.push(top->right);
        }
        
        reverse(ans.begin(), ans.end()); // Reverse the result to get postorder
        return ans; // Return the postorder result
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

    // Get the postorder traversal
    vector<int> result = solution.postorderTraversal(root);

    // Output the result using a traditional for loop
    cout << "Postorder Traversal: ";
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
