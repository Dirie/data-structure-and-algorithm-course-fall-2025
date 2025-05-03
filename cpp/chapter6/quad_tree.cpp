#include <iostream>
#include <memory>
using namespace std;

struct QuadTree {
    bool isValue;
    int value; // only used if isValue == true
    shared_ptr<QuadTree> lu, ru, ll, rl;

    // Constructor for leaf node
    QuadTree(int val) : isValue(true), value(val) {}

    // Constructor for internal node
    QuadTree(shared_ptr<QuadTree> lu,
             shared_ptr<QuadTree> ru,
             shared_ptr<QuadTree> ll,
             shared_ptr<QuadTree> rl)
        : isValue(false), lu(lu), ru(ru), ll(ll), rl(rl) {}
};

shared_ptr<QuadTree> rotate(shared_ptr<QuadTree> qt) {
    if (qt->isValue) {
        return make_shared<QuadTree>(qt->value);
    } else {
        return make_shared<QuadTree>(
            rotate(qt->rl),
            rotate(qt->ll),
            rotate(qt->ru),
            rotate(qt->lu)
        );
    }
}

void printTree(shared_ptr<QuadTree> qt, string indent = "") {
    if (qt->isValue) {
        cout << indent << qt->value << endl;
    } else {
        cout << indent << "Node" << endl;
        printTree(qt->lu, indent + "  LU-> ");
        printTree(qt->ru, indent + "  RU-> ");
        printTree(qt->ll, indent + "  LL-> ");
        printTree(qt->rl, indent + "  RL-> ");
    }
}

int main() {
    // Create a simple quad-tree:
    //        Node
    //      / | | \
    //     1  2 3  4
    auto A = make_shared<QuadTree>(1);
    auto B = make_shared<QuadTree>(2);
    auto C = make_shared<QuadTree>(3);
    auto D = make_shared<QuadTree>(4);

    auto root = make_shared<QuadTree>(A, B, C, D);

    cout << "Original QuadTree:" << endl;
    printTree(root);

    // Create a subtree starting with C that has no leaf nodes.
    // Let's make C an internal node and give it its own internal children.
    auto E = make_shared<QuadTree>(5);  // Internal node with value 5
    auto F = make_shared<QuadTree>(6);  // Internal node with value 6
    auto G = make_shared<QuadTree>(7);  // Internal node with value 7
    auto H = make_shared<QuadTree>(8);  // Internal node with value 8

    auto subtreeC = make_shared<QuadTree>(E, F, G, H);  // C is now an internal node with these children

    cout << "\nSubtree starting with C (no leaf nodes):" << endl;
    printTree(subtreeC);

    // Rotating the original tree
    auto rotated = rotate(root);

    cout << "\nRotated QuadTree (180 degrees):" << endl;
    printTree(rotated);

    return 0;
}
