DLList dll2;
dll2.insert_first(0);

ASSERT_ANY_THROW(dll2.remove_after(*dll2.first_node()));