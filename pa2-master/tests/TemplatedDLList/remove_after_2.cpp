TemplatedDLList<int> dll2;
ASSERT_ANY_THROW(dll2.remove_after(*dll2.first_node()));