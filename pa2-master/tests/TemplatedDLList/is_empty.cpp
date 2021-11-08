TemplatedDLList<int> intDll;

ASSERT_TRUE(intDll.is_empty());
ASSERT_TRUE(intDll.first_node() == intDll.after_last_node());

intDll.insert_first(0);
ASSERT_FALSE(intDll.is_empty());
ASSERT_FALSE(intDll.first_node() == intDll.after_last_node());