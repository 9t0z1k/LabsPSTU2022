#include <iostream>
#include "Tree.h"


int main() {
    Tree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Preorder Traversal: ";
    tree.preorderTraversal();

    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal();

    std::cout << "Postorder Traversal: ";
    tree.postorderTraversal();

    std::cout << "Searching for key 40: " << (tree.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for key 90: " << (tree.search(90) ? "Found" : "Not found") << std::endl;
    tree.visualizeTree();
    tree.remove(30);
    std::cout << "Inorder Traversal after removing key 30: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Max value: " << tree.findMaxValue() << std::endl;
    tree.visualizeTree();
    return 0;
}
