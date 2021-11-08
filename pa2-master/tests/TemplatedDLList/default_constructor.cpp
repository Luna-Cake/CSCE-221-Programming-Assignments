TemplatedDLList<int> intDll;
ASSERT_TRUE(intDll.first_node() == intDll.after_last_node());
ASSERT_TRUE(intDll.is_empty());

