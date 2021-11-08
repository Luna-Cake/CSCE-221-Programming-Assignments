BSTree t;
BSTree tt(move(t));

ASSERT_EQ(tt.get_root(),nullptr);
ASSERT_EQ(tt.get_size(),0);
ASSERT_EQ(t.get_root(),nullptr);
ASSERT_EQ(t.get_size(),0);