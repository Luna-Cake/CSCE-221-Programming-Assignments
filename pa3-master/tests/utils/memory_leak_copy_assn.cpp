#include "BSTree.h"
#include "test_functions.h"

int main()
{
    {
BSTree tree1;

BSTree tree2;
tree2 = tree1;
    }
    {
BSTree tree1;

tree1.insert(3);
tree1.insert(1);
tree1.insert(4);
tree1.insert(9);
tree1.insert(2);
tree1.insert(6);
tree1.insert(5);
tree1.insert(8);

BSTree tree2;
for (int i = 0; i < 20; i++) {
    tree2.insert(i*i);
}
tree2 = tree1;
    }
    
    {
        BSTree tree1;

tree1.insert(3);
tree1.insert(1);
tree1.insert(4);
tree1.insert(9);
tree1.insert(2);
tree1.insert(6);
tree1.insert(5);
tree1.insert(8);

BSTree tree2;
tree2 = tree1;
    }
    
    {
        BSTree tree1;
        tree1.insert(3);
tree1.insert(1);
tree1.insert(4);
tree1.insert(9);
tree1.insert(2);
tree1.insert(6);
tree1.insert(5);
tree1.insert(8);

BSTree tree2;
tree1 = tree2;
    }
    
    {
        BSTree tree1;

tree1.insert(3);
tree1.insert(1);
tree1.insert(4);
tree1.insert(9);
tree1.insert(2);
tree1.insert(6);
tree1.insert(5);
tree1.insert(8);

tree1 = tree1;
    }
    
    {
        BSTree tree1, tree2, tree3;

tree1.insert(3);
tree1.insert(1);
tree1.insert(4);
tree1.insert(9);
tree1.insert(2);
tree1.insert(6);
tree1.insert(5);
tree1.insert(8);

    tree3 = tree2 = tree1;
    }

}
