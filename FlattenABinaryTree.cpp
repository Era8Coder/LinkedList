#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* &root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root -> left != NULL){
        flatten(root -> left);              // Flattening left side of the root :)

        TreeNode* temp = root->right;       // Storing the right side of the root in the temp
        root->right = root->left;           
        root->left  = NULL;

        TreeNode* tail = root->right;           // Finding the root of the left part of the tree

        while(tail->right != NULL){
            tail = tail -> right;
        }

        tail -> right = temp;           // Make the Actual right Equal to Temp
    }

    flatten(root->right);
}

void display_tree(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    display_tree(root->left);
    display_tree(root->right);
}

void display(TreeNode* root){
    TreeNode* temp = root;
    while(temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> right;
    }
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right= new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right= new TreeNode(3);
    root->right->right= new TreeNode(6);
    display_tree(root);
    flatten(root);
    cout << endl;
    display(root);
    return 0;
}