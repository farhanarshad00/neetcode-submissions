/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool DFS(TreeNode* node, long long lower, long long upper){
        if(!node){return true;}

        if(node->val >= upper || node->val <= lower){
            return false;
        }

        if(DFS(node->left,lower,node->val) && DFS(node->right,node->val,upper)){
            return true;
        }else{
            return false;
        }

    }

    bool isValidBST(TreeNode* root) {
        long long l_bound = LLONG_MIN;
        long long u_bound = LLONG_MAX;

        return DFS(root,l_bound,u_bound);
        
    }
};

/*
* What is known:
* A binary search tree requires that the root node be the smallest value in the right subtree and the largest value in the left subtree.
* The same must be true for all the children in the tree as well.
* That is to say for every node in the tree, its left child must be less than it and its right child must be greater than it.
*
* Approach: Recursively walk from the bottom up
* Create a Depth-First Search helper function DFS that returns a bool and takes in a TreeNode* node, long long lower, and long long upper.
*   Check if the node passed in is null: if so return true.
*   Check if the node's children do not fit the structure of a BST: if so return false.
*   Recursively check the nodes children by calling DFS using them as parameter and the node->val as either the lower or upper bound depending on which child is passed to the DFS function.
* In isValidBST, initialize a lower and upper bound for the root node at the bounds of long long.
* Then return the value of DFS(root,lower bound, upper bound).
*/