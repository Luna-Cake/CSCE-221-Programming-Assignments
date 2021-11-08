DLList dll;
ASSERT_TRUE(dll.is_empty());
dll.insert_first(0);
ASSERT_FALSE(dll.is_empty());