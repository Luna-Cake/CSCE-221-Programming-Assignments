#include "RefBSTree.h"
#include "test_functions.h"

BSTree t;
t.insert(6);
t.insert(7);
t.insert(8);
t.insert(1);
t.insert(2);
t.insert(0);

auto ptr = t.get_root()->left;

BSTree tt(move(t));

ASSERT_EQ(t.get_size(),0);
ASSERT_EQ(t.get_root(),nullptr);
ASSERT_EQ(tt.get_root()->left, ptr);

t.insert(6);
t.insert(7);
t.insert(8);
t.insert(1);
t.insert(2);
t.insert(0);

ASSERT_EQ(verify_equality(tt,t),true);


