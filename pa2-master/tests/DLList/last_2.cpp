// Last element inserted with insert_after
DLList dll2;
dll2.insert_first(2);
dll2.insert_first(1);
dll2.insert_after(*(dll2.after_last_node()->prev), 3);

ASSERT_EQ(dll2.last(), 3);