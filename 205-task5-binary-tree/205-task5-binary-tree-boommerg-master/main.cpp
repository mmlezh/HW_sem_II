#include "tree.hpp"
#include <iostream>

int main()
{
    TreeNode *tree = nullptr;
    size_t size;
    int sum;
    std::cin >> size;
    int *data = new int[size];
    for (size_t i = 0; i < size; i++) {
        std::cin >> data[i];
    }
    tree = readBFS(size, data, tree, 0);
    std::cin >> sum;
    std::cout << isSearchTree(tree) << std::endl;
    std::cout << maxPaths(tree, sum) << std::endl;
    delete[] data;
    deleteTree(tree);
    return 0;
}