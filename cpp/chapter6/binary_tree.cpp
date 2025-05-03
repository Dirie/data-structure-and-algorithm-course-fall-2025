#include <iostream>
#include <memory>

struct TreeNode {
    int value;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int v, std::shared_ptr<TreeNode> l, std::shared_ptr<TreeNode> r)
        : value(v), left(l), right(r) {}
};

using Tree = std::shared_ptr<TreeNode>;

// Constructors
Tree EmptyTree() {
    return nullptr;
}

Tree MakeTree(int v, Tree l, Tree r) {
    return std::make_shared<TreeNode>(v, l, r);
}

Tree Leaf(int v) {
    return MakeTree(v, EmptyTree(), EmptyTree());
}

// Selectors
bool isEmpty(Tree t) {
    return t == nullptr;
}

int root(Tree t) {
    if (isEmpty(t)) throw std::runtime_error("Empty tree has no root");
    return t->value;
}

Tree left(Tree t) {
    if (isEmpty(t)) throw std::runtime_error("Empty tree has no left child");
    return t->left;
}

Tree right(Tree t) {
    if (isEmpty(t)) throw std::runtime_error("Empty tree has no right child");
    return t->right;
}

// Generic print function (no specific order)
void printTree(Tree t) {
    if (!isEmpty(t)) {
        std::cout << "Node: " << root(t) << std::endl;
        std::cout << "---------"<<std::endl;
        if (!isEmpty(left(t)))
            std::cout << "  Left of " << root(t) << ": " << root(left(t)) << std::endl;
        else
            std::cout << "  Left of " << root(t) << ": Empty" << std::endl;

        if (!isEmpty(right(t)))
            std::cout << "  Right of " << root(t) << ": " << root(right(t)) << std::endl;
        else
            std::cout << "  Right of " << root(t) << ": Empty" << std::endl;

        printTree(left(t));
        printTree(right(t));
    }
}

int main() {
    Tree t = MakeTree(8,
                MakeTree(3,
                    Leaf(1),
                    MakeTree(6, EmptyTree(), Leaf(7))
                ),
                MakeTree(11,
                    MakeTree(9, EmptyTree(), Leaf(10)),
                    MakeTree(14, Leaf(12), Leaf(15))
                )
            );

    printTree(t);

//     8
//     / \
//    3    11
//   / \   /  \
//  1   6 9    14
//       \ \    / \
//        7 10 12 15
//         
//         

    return 0;
}
