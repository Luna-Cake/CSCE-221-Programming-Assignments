 // First element inserted with insert_first
DLList dll;
dll.insert_first(3);
dll.insert_first(2);
dll.insert_first(1);

ASSERT_EQ(dll.first(), 1);