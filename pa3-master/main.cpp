#include "test_functions.h"
#include <cstdlib>
#include <ctime>
#include <set>

int main () {
    std::set<int> set;
    BSTree tree1;
    // BSTree ttree1;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int num = rand() % 10000;
        if (set.count(num) == 0) {
            set.insert(num);
            tree1.insert(num);
            // ttree1.insert(num);
        }
    }
    // // BSTree tree2(tree1);
    // tree1 = std::move(tree1);
    // tree1.inorder(std::cout);
    // std::cout << std::endl;
    // ttree1.inorder(std::cout);
    // std::cout << std::endl;

    // tree1.insert(2);
    // tree1.insert(1);
    // tree1.insert(3);
    BSTree tree2;
    tree2 = std::move(tree1);
    tree1.print_level_by_level(std::cout);
    tree2.print_level_by_level(std::cout);

    std::cout << tree1.get_size() << std::endl;
    std::cout << tree2.get_size() << std::endl;
    std::cout << std::endl;
}