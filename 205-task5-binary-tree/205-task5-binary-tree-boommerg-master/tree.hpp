#ifndef tree_hpp
#define tree_hpp

#include <iostream>
#include <limits.h>

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *readBFS(size_t size, int data[], TreeNode *tree, size_t indx);
bool isSearchTree(TreeNode *tree, int min = INT_MIN, int max = INT_MAX);
void DFS(TreeNode *tree, int sum, int cursum, int *count, bool isCall);
int maxPaths(TreeNode *tree, int sum);
void deleteTree(TreeNode *tree);

#endif
