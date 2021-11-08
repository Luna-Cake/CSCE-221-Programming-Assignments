DLList list1;
ASSERT_TRUE(list1.is_empty());
ASSERT_EQ(list1.first_node(), list1.after_last_node());