#include "tree.hpp"
#include <iostream>

TreeNode *readBFS(size_t size, int *data, TreeNode *tree, size_t indx)
{
    if (indx < size) {
        /*
            tree->value = data[indx];
            tree->left = nullptr;
            tree->right = nullptr;
        */
        TreeNode *tempNode;
        tempNode = new TreeNode;
        tempNode->value = data[indx];
        tempNode->left = nullptr;
        tempNode->right = nullptr;
        tree = tempNode;
        tree->left = readBFS(size, data, tree->left, 2 * indx + 1);
        tree->right = readBFS(size, data, tree->right, 2 * indx + 2);
    }
    return tree;
}

bool isSearchTree(TreeNode *tree, int min, int max)
{
    if (tree == nullptr) {
        return true;
    }
    if (min < tree->value && tree->value < max) {
        return isSearchTree(tree->left, min, tree->value) &&
               isSearchTree(tree->right, tree->value, max);
    }
    return false;
}

void DFS(TreeNode *tree, int sum, int cursum, int *count, bool isCall)
{
    // int temp = cursum;
    cursum += tree->value;
    if (cursum == sum) {
        (*count)++;
    }
    if (tree->left != nullptr) {
        /*
        if(tempSum == 0)
            DFS(tree->left, sum, 0, count);
        */
        if (!isCall) {
            DFS(tree->left, sum, 0, count, true);
        }
        DFS(tree->left, sum, cursum, count, isCall);
    }

    if (tree->right != nullptr) {
        /*
        if(tempSum == 0)
            DFS(tree->right, sum, 0, count);
        */
        if (!isCall) {
            DFS(tree->right, sum, 0, count, true);
        }
        DFS(tree->right, sum, cursum, count, isCall);
    }
}

int maxPaths(TreeNode *tree, int sum)
{
    if (tree == nullptr) {
        return 0;
    }
    int count = 0;
    DFS(tree, sum, 0, &count, false);
    return count;
}

void deleteTree(TreeNode *tree)
{
    if (tree->left != nullptr) {
        deleteTree(tree->left);
    }
    if (tree->right != nullptr) {
        deleteTree(tree->right);
    }
    delete tree;
}